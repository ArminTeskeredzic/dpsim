/* Copyright 2017-2021 Institute for Automation of Complex Power Systems,
 *                     EONERC, RWTH Aachen University
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *********************************************************************************/
#include <DPsim.h>
#include "../Examples.h"

using namespace DPsim;
using namespace CPS;
using namespace CIM::Examples::Grids::generic_model_C_A;
//using namespace CPS::CIM;

ScenarioConfig generic_model_C_A;
//Examples::Components::SynchronousGeneratorKundur::myMachineParameters
 //syngenKundur;
//Switch to trigger fault at generator terminal
Real SwitchOpen = 1e16;
Real SwitchClosed = 1e-12;
//void scenario_C_step_A(String simName, Real timeStep, Real finalTime){
void scenario_C_step_C(String simName, Real timeStep, Real finalTime, Bool startFaultEvent, Bool endFaultEvent, Real startTimeFault, Real endTimeFault, Bool useVarResSwitch, Real cmdInertia_G1, Real cmdDamping_G1) {
	// ----- POWERFLOW FOR INITIALIZATION -----
	Real timeStepPF = finalTime;
	Real finalTimePF = finalTime+timeStepPF;
	String simNamePF = simName + "_PF";
	Logger::setLogDir("logs/" + simNamePF);

	// Components // EDITED ARMIN
	auto BUS_gas_PF = SimNode<Complex>::make("BUS_gas", PhaseType::Single);
	auto BUS_b_PF = SimNode<Complex>::make("BUS_b", PhaseType::Single);
	auto BUS_TR_ld2_PF = SimNode<Complex>::make("BUS_TR_ld2", PhaseType::Single);
	auto BUS_l2_PF = SimNode<Complex>::make("BUS_l2", PhaseType::Single);
	auto BUS_a_PF = SimNode<Complex>::make("BUS_a", PhaseType::Single);
	auto BUS_shunt_b_PF = SimNode<Complex>::make("BUS_shunt_b", PhaseType::Single);
	auto BUS_shunt_a_PF = SimNode<Complex>::make("BUS_shunt_a", PhaseType::Single);
	auto BUS_shunt_b_load_PF = SimNode<Complex>::make("BUS_shunt_b_load", PhaseType::Single);
	auto BUS_shunt_a_load_PF = SimNode<Complex>::make("BUS_shunt_a_load", PhaseType::Single);

	//Synchronous generator 1 // EDITED ARMIN
	auto GEN_gas_PF = SP::Ph1::SynchronGenerator::make("GEN_gas", Logger::Level::debug);
	// setPointVoltage is defined as the voltage at the transfomer primary side and should be transformed to network side
	GEN_gas_PF->setParameters(generic_model_C_A.nomPower_G1, generic_model_C_A.nomPhPhVoltRMS_G1, generic_model_C_A.initActivePower_G1, 10.5e3, PowerflowBusType::VD);
	GEN_gas_PF->setBaseVoltage(10.5e3);
	

	// auto extnetPF = SP::Ph1::NetworkInjection::make("Slack", Logger::Level::debug);
	// extnetPF->setParameters(generic_model_C_A.nomPhPhVoltRMS_G1/*scenario.systemNominalVoltage*/);
	// extnetPF->setBaseVoltage(generic_model_C_A.nomPhPhVoltRMS_G1/*scenario.systemNominalVoltage*/);
	// extnetPF->modifyPowerFlowBusType(PowerflowBusType::VD);

	auto TR_gas_PF = std::make_shared<SP::Ph1::Transformer>("TR_gas", Logger::Level::debug);
    TR_gas_PF->setParameters(10.5e3/*nomVoltageEnd1*/,  generic_model_C_A.Vnom/*nomVoltageEnd2*/, generic_model_C_A.nomPower_G1 /*ratedPower*/, 
				(10.5e3/generic_model_C_A.Vnom)/*ratioAbs*/, 0 /*ratioPhase*/, 1.82078864*2 /*resistance*/, 
	 0.15518646*2 /*inductance*/);
    TR_gas_PF->setBaseVoltage(generic_model_C_A.Vnom);

	auto TR_ld2_PF = std::make_shared<SP::Ph1::Transformer>("TR_ld2", Logger::Level::debug);
    TR_ld2_PF->setParameters(10.0e3/*nomVoltageEnd1*/,  generic_model_C_A.Vnom/*nomVoltageEnd2*/, generic_model_C_A.nomPower_G1 /*ratedPower*/, 
				(10.0e3/generic_model_C_A.Vnom)/*ratioAbs*/, 0 /*ratioPhase*/, 1.82078864*2 /*resistance*/, 
	 0.15518646*2 /*inductance*/);
    TR_ld2_PF->setBaseVoltage(generic_model_C_A.Vnom);
	
	// Loads
	auto dummy_load_bus_b_PF = SP::Ph1::Load::make("dummy_load_bus_b", Logger::Level::debug);
	dummy_load_bus_b_PF->setParameters(0.0, 0.0, 220e3);

	auto LOAD_2a_PF = SP::Ph1::Load::make("LOAD_2a", Logger::Level::debug);
	LOAD_2a_PF->setParameters(5e6, 3.098721e6, 10e3);

	auto LOAD_2b_PF = SP::Ph1::Load::make("LOAD_2b", Logger::Level::debug);
	LOAD_2b_PF->setParameters(5e6, 0, 10e3);

	// shunt
	auto shunt_SR_bcb_PF = SP::Ph1::Shunt::make("shunt_SR_bcb", Logger::Level::debug);
	shunt_SR_bcb_PF->setParameters(generic_model_C_A.shuntConduntanceB /*conduntance*/, generic_model_C_A.shuntSusceptanceB /*susceptance*/);
	shunt_SR_bcb_PF->setBaseVoltage(generic_model_C_A.Vnom); // 2.0659e-07 - 2.0659e-05i


	auto shunt_SR_acb_PF = SP::Ph1::Shunt::make("shunt_SR_acb", Logger::Level::debug);
	shunt_SR_acb_PF->setParameters(generic_model_C_A.shuntConduntanceA /*conduntance*/, generic_model_C_A.shuntSusceptanceA /*susceptance*/);
	shunt_SR_acb_PF->setBaseVoltage(generic_model_C_A.Vnom); // 2.0659e-07 - 2.0659e-05i

	//Line1
	// auto cable_PF = SP::Ph1::PiLine::make("cable", Logger::Level::debug);
	// cable_PF->setParameters(generic_model_C_A.cableResistance /*R/km * km*/, generic_model_C_A.cableInductance /*L/km * km*/, 
	// 						generic_model_C_A.cableCapacitance /*Capacitance*/, generic_model_C_A.cableConductance);
	// cable_PF->setBaseVoltage(generic_model_C_A.Vnom);

	auto line_a_load_PF = SP::Ph1::PiLine::make("breaker_a", Logger::Level::debug);
	line_a_load_PF->setParameters(1e-8, 1e-5, 0, 1e-15);
	line_a_load_PF->setBaseVoltage(generic_model_C_A.Vnom);

	auto line_b_load_PF = SP::Ph1::PiLine::make("breaker_b", Logger::Level::debug);
	line_b_load_PF->setParameters(1e-8, 1e-5, 0, 1e-15);
	line_b_load_PF->setBaseVoltage(generic_model_C_A.Vnom);



	// breaker - dummy line
	auto line_CB1_ld2_PF = SP::Ph1::PiLine::make("breaker_CB1_ld2", Logger::Level::debug);
	line_CB1_ld2_PF->setParameters(1e-8, 1e-5, 0, 1e-15);
	line_CB1_ld2_PF->setBaseVoltage(220e3);

	auto line_bus_b_shunt_b_PF = SP::Ph1::PiLine::make("line_bus_b_shunt_b", Logger::Level::debug);
	line_bus_b_shunt_b_PF->setParameters(1e3, 1e-5, 0, 1e-15);
	line_bus_b_shunt_b_PF->setBaseVoltage(220e3);

	// auto line_bus_a_shunt_a_PF = SP::Ph1::PiLine::make("line_bus_a_shunt_a", Logger::Level::debug);
	// line_bus_a_shunt_a_PF->setParameters(1e8, 1e-5, 0, 1e-15);
	// line_bus_a_shunt_a_PF->setBaseVoltage(220e3);

	auto dummy_load_bus_b_shunt_PF = SP::Ph1::Load::make("shunt_bus_b", Logger::Level::debug);
	dummy_load_bus_b_shunt_PF->setParameters(0.0, 0.0, 220e3);

	auto dummy_load_bus_a_shunt_PF = SP::Ph1::Load::make("shunt_bus_a", Logger::Level::debug);
	dummy_load_bus_a_shunt_PF->setParameters(0.0, 0.0, 220e3);


	auto cable2_PF = SP::Ph1::PiLine::make("cable", Logger::Level::debug);
	cable2_PF->setParameters(1e-6 /*R/km * km*/, 1e-6 /*L/km * km*/, 
							0 /*Capacitance*/, 0);
	cable2_PF->setBaseVoltage(generic_model_C_A.Vnom);

	// Topology
	GEN_gas_PF->connect({ BUS_gas_PF });
	TR_gas_PF->connect({ BUS_gas_PF, BUS_b_PF});
	TR_ld2_PF->connect({ BUS_l2_PF, BUS_b_PF});
	//dummy_load_bus_b_PF->connect({ BUS_b_PF });
	LOAD_2a_PF->connect({ BUS_l2_PF });
	LOAD_2b_PF->connect({ BUS_l2_PF });
	//line_bus_b_shunt_b_PF->connect({ BUS_b_PF, BUS_shunt_b_PF});
	//cable2_PF->connect({ BUS_shunt_b_PF, BUS_a_PF});
	//line_a_load_PF->connect({ BUS_a_PF, BUS_shunt_a_load_PF});
	//line_b_load_PF->connect({ BUS_shunt_b_PF, BUS_shunt_b_load_PF});
	//dummy_load_bus_b_shunt_PF->connect({ BUS_shunt_b_load_PF });
	//dummy_load_bus_a_shunt_PF->connect({ BUS_shunt_a_load_PF });

	auto systemPF = SystemTopology(50, // das ist freq??
			SystemNodeList{BUS_gas_PF, BUS_b_PF,  BUS_l2_PF},
			SystemComponentList{GEN_gas_PF, TR_gas_PF, TR_ld2_PF, LOAD_2a_PF, LOAD_2b_PF});

	// Logging
	auto loggerPF = DataLogger::make(simNamePF);
	loggerPF->logAttribute("V_BUS_b_PF", BUS_b_PF->attribute("v"));
	loggerPF->logAttribute("V_BUS_gas_PF", BUS_gas_PF->attribute("v"));

	// Simulation
	Simulation simPF(simNamePF, Logger::Level::debug);
	simPF.setSystem(systemPF);
	simPF.setTimeStep(timeStepPF);
	simPF.setFinalTime(finalTimePF);
	simPF.setDomain(Domain::SP);
	simPF.setSolverType(Solver::Type::NRP);
	simPF.setSolverAndComponentBehaviour(Solver::Behaviour::Initialization);
	simPF.doInitFromNodesAndTerminals(true);
	simPF.addLogger(loggerPF);
	simPF.run();



	// ----- Dynamic simulation ------
	String simNameEMT = simName + "_EMT";
	Logger::setLogDir("logs/"+simNameEMT);

	// Nodes
	auto BUS_gas_EMT = SimNode<Real>::make("BUS_gas", PhaseType::ABC);;
	auto BUS_b_EMT = SimNode<Real>::make("BUS_b", PhaseType::ABC);
	auto BUS_TR_ld2_EMT = SimNode<Real>::make("BUS_TR_ld2", PhaseType::ABC);
	auto BUS_l2_EMT = SimNode<Real>::make("BUS_l2", PhaseType::ABC);
	auto BUS_a_EMT = SimNode<Real>::make("BUS_a", PhaseType::ABC);
	auto BUS_shunt_b_EMT = SimNode<Real>::make("BUS_shunt_b", PhaseType::ABC);
	auto BUS_shunt_a_EMT = SimNode<Real>::make("BUS_shunt_a", PhaseType::ABC);
	auto BUS_shunt_b_load_EMT = SimNode<Real>::make("BUS_shunt_b_load", PhaseType::ABC);
	auto BUS_shunt_a_load_EMT = SimNode<Real>::make("BUS_shunt_a_load", PhaseType::ABC);

	auto BUS_test_EMT = SimNode<Real>::make("BUS_test", PhaseType::ABC);
	
	// Components

	auto GEN_gas_EMT =
      CPS::EMT::Ph3::SynchronGeneratorVBR::make("GEN_gas", Logger::Level::debug);
 		 GEN_gas_EMT->setBaseAndOperationalPerUnitParameters(
      50e6/*nomPower*/, 10.5e3/*nomVoltage*/, 50/*nomFreq*/,
      2/*poleNum*/, 1300/*nomFieldCurr*/, 0.002/*Rs*/,
      2.4/*Ld*/, 1.33 /*Lq*/, 0.31/*Ld_t*/, 1.2/*Lq_t*/,
      0.24/*Ld_s*/, 0.35/*Lq_s*/, 0.135/*Ll*/, 1.45/*Td0_t*/,
      0.000001/*Tq0_t*/, 0.022/*Td0_s*/, 0.0095/*Tq0_s*/,
      5/*H*/);


	//GEN_gas_EMT->addGovernor(0.3, 7.0, 0.5, 0.3,
    //                 0.3, 0.4, 20, 0.1,
    //                 0.3, 15.726322438662876e6 / 50e6,
    //                 15.726322438662876e6 / 50e6);

	GEN_gas_EMT->addGovernor(0.3 /*Real Ta 0.3*/, 12.0 /*Real Tb 7.0*/, 0.5 /*Real Tc 0.5*/, 0.3 /*0.33 Real Fa 0.3*/,
                     0.3 /*0.065 Real Fb 0.3*/, 0.4 /*0.055 Real Fc 0.4*/, 20 /*Real K 20*/, 0.1 /*Real Tsr 0.1*/,
                     0.3 /*Real Tsm 0.3*/, 10.064680849042885e6 / 50e6 /*Real Tm_init*/,
                     10.064680849042885e6 / 50e6 /*Real PmRef*/);
					//  (Real Ta, Real Tb, Real Tc, Real Fa,
                    //                       Real Fb, Real Fc, Real K, Real Tsr,
                    //                       Real Tsm, Real Tm_init, Real PmRef)

    //GEN_gas_EMT->addExciter(0.06, 46, 0.46, -0.0435,
    //                1, 0.1, 0.02);
	GEN_gas_EMT->addExciter(0.01 /*Real Ta*/, 500 /*Real Ka*/, 0.46 /*Real Te*/, 0.0435 /*Real Ke*/,
                         1 /*Real Tf*/, 0.1 /*Real Kf*/, 0.01 /*Real Tr*/, 7.65 /*MaxVr*/, -6.5 /*MinVr*/);

	
// 	auto vs = EMT::Ph3::VoltageSource::make("GEN_gas", Logger::Level::debug);
//   vs->setParameters(
//       CPS::Math::singlePhaseVariableToThreePhase(CPS::Math::polar(10.5e3, 0)),
//       50);

	// Trafo
	auto TR_gas_EMT = EMT::Ph3::Transformer::make("TR_gas", "TR_gas", Logger::Level::debug, true);
	TR_gas_EMT->setParameters(10.5e3, generic_model_C_A.Vnom, generic_model_C_A.nomPower_G1,
                     (10.5e3/generic_model_C_A.Vnom), 0, Math::singlePhaseParameterToThreePhase(1.82078864*2),
                     Math::singlePhaseParameterToThreePhase(0.15518646*2));

	
	auto TR_ld2_EMT = EMT::Ph3::Transformer::make("TR_ld2", "TR_ld2", Logger::Level::debug, true);
	TR_ld2_EMT->setParameters(10.0e3, generic_model_C_A.Vnom, generic_model_C_A.nomPower_G1,
                     (10.0e3/generic_model_C_A.Vnom), 0, Math::singlePhaseParameterToThreePhase(1.82078864*2),
                     Math::singlePhaseParameterToThreePhase(0.15518646*2));

	
	


	
	//Load
	auto dummy_load_bus_b_EMT = EMT::Ph3::RXLoad::make("dummy_load_bus_b", Logger::Level::debug);
	dummy_load_bus_b_EMT->setParameters(CPS::Math::singlePhasePowerToThreePhase(0), 
	CPS::Math::singlePhasePowerToThreePhase(0), generic_model_C_A.Vnom);

	auto LOAD_2a_EMT = EMT::Ph3::RXLoad::make("LOAD_2a", Logger::Level::debug);
	LOAD_2a_EMT->setParameters(CPS::Math::singlePhasePowerToThreePhase(5.0e6), 
	CPS::Math::singlePhasePowerToThreePhase(3.098721e6), 10.0e3);

	auto LOAD_2b_EMT = EMT::Ph3::RXLoad::make("LOAD_2b", Logger::Level::debug);
	LOAD_2b_EMT->setParameters(CPS::Math::singlePhasePowerToThreePhase(5.0e6), 
	CPS::Math::singlePhasePowerToThreePhase(0), 10.0e3);

	//Breaker

	auto cable_EMT = EMT::Ph3::PiLine::make("cable", Logger::Level::debug);
	cable_EMT->setParameters(Math::singlePhaseParameterToThreePhase(generic_model_C_A.cableResistance), 
	                      Math::singlePhaseParameterToThreePhase(generic_model_C_A.cableInductance), 
					      Math::singlePhaseParameterToThreePhase(generic_model_C_A.cableCapacitance),
						  Math::singlePhaseParameterToThreePhase(generic_model_C_A.cableConductance));

	// auto line_load2_a_EMT = EMT::Ph3::PiLine::make("line_load2_a", Logger::Level::debug);
	// line_load2_a_EMT->setParameters(Math::singlePhaseParameterToThreePhase(1e-8), 
	//                       Math::singlePhaseParameterToThreePhase(1e-5), 
	// 				      Math::singlePhaseParameterToThreePhase(0),
	// 					  Math::singlePhaseParameterToThreePhase(1e-15));
	
	// auto line_load2_b_EMT = EMT::Ph3::PiLine::make("line_load2_b", Logger::Level::debug);
	// line_load2_b_EMT->setParameters(Math::singlePhaseParameterToThreePhase(1e-8), 
	//                       Math::singlePhaseParameterToThreePhase(1e-5), 
	// 				      Math::singlePhaseParameterToThreePhase(0),
	// 					  Math::singlePhaseParameterToThreePhase(1e-15));

	
	auto breaker_bus_b_shunt_b_EMT = CPS::EMT::Ph3::Switch::make("line_bus_b_shunt_b", Logger::Level::debug);
	breaker_bus_b_shunt_b_EMT->setParameters(Math::singlePhaseParameterToThreePhase(SwitchOpen), 
							Math::singlePhaseParameterToThreePhase(SwitchClosed));
	breaker_bus_b_shunt_b_EMT->openSwitch();

	auto breaker_a_EMT = CPS::EMT::Ph3::Switch::make("breaker_a", Logger::Level::debug);
	breaker_a_EMT->setParameters(Math::singlePhaseParameterToThreePhase(SwitchOpen), 
							Math::singlePhaseParameterToThreePhase(SwitchClosed));
	breaker_a_EMT->closeSwitch();

	auto breaker_b_EMT = CPS::EMT::Ph3::Switch::make("breaker_b", Logger::Level::debug);
	breaker_b_EMT->setParameters(Math::singlePhaseParameterToThreePhase(SwitchOpen), 
							Math::singlePhaseParameterToThreePhase(SwitchClosed));
	breaker_b_EMT->closeSwitch();

	// auto load_shunt_bus_b_EMT = EMT::Ph3::RXLoad::make("shunt_bus_b", Logger::Level::debug);
	// load_shunt_bus_b_EMT->setParameters(CPS::Math::singlePhasePowerToThreePhase((1.0*220000)*(1.0*220000)/(322698.9333)), 
	// CPS::Math::singlePhasePowerToThreePhase((1.0*220000)*(1.0*220000)/(3226.9893)), generic_model_C_A.Vnom);

	// auto load_shunt_bus_a_EMT = EMT::Ph3::RXLoad::make("shunt_bus_a", Logger::Level::debug);
	// load_shunt_bus_a_EMT->setParameters(CPS::Math::singlePhasePowerToThreePhase((1.0*220000)*(1.0*220000)/(322698.9333)), 
	// CPS::Math::singlePhasePowerToThreePhase((1.0*220000)*(1.0*220000)/(3226.9893)), generic_model_C_A.Vnom);

	auto load_shunt_bus_b_EMT_test = EMT::Ph3::RXLoad::make("shunt_bus_b", Logger::Level::debug);
	load_shunt_bus_b_EMT_test->setParameters(CPS::Math::singlePhasePowerToThreePhase(1.85328209568567633e6),   //2.15328209568567633e6
	CPS::Math::singlePhasePowerToThreePhase(15.328209566512838e6), generic_model_C_A.Vnom); //35.328209566512838e6

	auto load_shunt_bus_a_EMT_test = EMT::Ph3::RXLoad::make("shunt_bus_a", Logger::Level::debug);
	load_shunt_bus_b_EMT_test->setParameters(CPS::Math::singlePhasePowerToThreePhase(1.85328209568567633e6), 
	CPS::Math::singlePhasePowerToThreePhase(15.328209566512838e6), generic_model_C_A.Vnom);


	auto test_load_EMT = EMT::Ph3::RXLoad::make("test_load", Logger::Level::debug);
	test_load_EMT->setParameters(CPS::Math::singlePhasePowerToThreePhase(10e6), 
	CPS::Math::singlePhasePowerToThreePhase(65.328209566512838e6), generic_model_C_A.Vnom);
	
	auto breaker_test_EMT = CPS::EMT::Ph3::Switch::make("breaker_test", Logger::Level::debug);
	breaker_test_EMT->setParameters(Math::singlePhaseParameterToThreePhase(SwitchOpen), 
							Math::singlePhaseParameterToThreePhase(SwitchClosed));
	breaker_test_EMT->openSwitch();
	
	// Topology
	GEN_gas_EMT->connect({ BUS_gas_EMT });
	//vs->connect({ BUS_gas_EMT, SimNode<Real>::GND });
	TR_gas_EMT->connect({ BUS_gas_EMT, BUS_b_EMT});
	TR_ld2_EMT->connect({BUS_l2_EMT, BUS_b_EMT });
	//dummy_load_bus_b_EMT->connect({ BUS_b_EMT });
	LOAD_2a_EMT->connect({ BUS_l2_EMT });
	LOAD_2b_EMT->connect({ BUS_l2_EMT });
	breaker_bus_b_shunt_b_EMT->connect({ BUS_b_EMT, BUS_shunt_b_EMT});
	cable_EMT->connect({ BUS_shunt_b_EMT, BUS_a_EMT});
	breaker_a_EMT->connect({ BUS_a_EMT, BUS_shunt_a_load_EMT});
	breaker_b_EMT->connect({ BUS_shunt_b_EMT, BUS_shunt_b_load_EMT});
	load_shunt_bus_b_EMT_test->connect({ BUS_shunt_b_load_EMT });
	load_shunt_bus_a_EMT_test->connect({ BUS_shunt_a_load_EMT });

	//breaker_test_EMT->connect({ BUS_a_EMT, BUS_test_EMT});
	//test_load_EMT->connect({ BUS_a_EMT });

	auto systemEMT = SystemTopology(50,
			SystemNodeList{BUS_gas_EMT, BUS_b_EMT, BUS_l2_EMT, BUS_shunt_b_EMT, BUS_a_EMT, BUS_shunt_b_load_EMT, BUS_shunt_a_load_EMT/*, BUS_test_EMT*/},
			SystemComponentList{GEN_gas_EMT, TR_gas_EMT, TR_ld2_EMT, LOAD_2a_EMT, LOAD_2b_EMT,
								breaker_bus_b_shunt_b_EMT, cable_EMT, load_shunt_bus_b_EMT_test, breaker_b_EMT, breaker_a_EMT, load_shunt_bus_a_EMT_test
								/*,breaker_test_EMT, test_load_EMT*/});

	for (auto attr : breaker_bus_b_shunt_b_EMT->attributes()) {
    	std::string name = attr.first;
    	std::cout << name << std::endl;
  	}

	// Initialization of dynamic topology
	systemEMT.initWithPowerflow(systemPF, Domain::EMT);

	


	// Logging
	auto loggerEMT = DataLogger::make(simNameEMT);
	loggerEMT->logAttribute("BUS_gas_EMT_v", BUS_gas_EMT->attribute("v"));
	loggerEMT->logAttribute("BUS_b_EMT_v", BUS_b_EMT->attribute("v"));
	loggerEMT->logAttribute("BUS_a_EMT_v", BUS_a_EMT->attribute("v"));

	loggerEMT->logAttribute("cable_i", cable_EMT->attribute("i_intf"));

	loggerEMT->logAttribute("breaker_a_EMT_i", breaker_a_EMT->attribute("i_intf"));
	loggerEMT->logAttribute("breaker_b_EMT_i", breaker_b_EMT->attribute("i_intf"));
	loggerEMT->logAttribute("breaker_bus_b_shunt_b_EMT_i", breaker_bus_b_shunt_b_EMT->attribute("i_intf"));


	loggerEMT->logAttribute("GEN_gas_EMT_w_r", GEN_gas_EMT->attribute("w_r"));
	loggerEMT->logAttribute("GEN_gas_EMT_P_elec", GEN_gas_EMT->attribute("P_elec"));
	loggerEMT->logAttribute("GEN_gas_EMT_Q_elec", GEN_gas_EMT->attribute("Q_elec"));
	loggerEMT->logAttribute("GEN_gas_EMT_P_mech", GEN_gas_EMT->attribute("P_mech"));
	loggerEMT->logAttribute("GEN_gas_EMT_i_intf", GEN_gas_EMT->attribute("i_intf"));
	loggerEMT->logAttribute("GEN_gas_EMT_v_intf", GEN_gas_EMT->attribute("v_intf"));
	loggerEMT->logAttribute("GEN_gas_EMT_delta_r", GEN_gas_EMT->attribute("delta_r"));
	loggerEMT->logAttribute("GEN_gas_EMT_T_e", GEN_gas_EMT->attribute("T_e"));

	loggerEMT->logAttribute("LOAD_2a_P", LOAD_2a_EMT->attribute("P"));
	loggerEMT->logAttribute("LOAD_2a_voltage", LOAD_2a_EMT->attribute("v_intf"));
	loggerEMT->logAttribute("LOAD_2a_current", LOAD_2a_EMT->attribute("i_intf"));
	loggerEMT->logAttribute("LOAD_2b_voltage", LOAD_2b_EMT->attribute("v_intf"));
	loggerEMT->logAttribute("LOAD_2b_current", LOAD_2b_EMT->attribute("i_intf"));



	Simulation simEMT(simNameEMT, Logger::Level::debug);
  	simEMT.doInitFromNodesAndTerminals(true);
  	simEMT.setSystem(systemEMT);
  	simEMT.setTimeStep(timeStep);
  	simEMT.setFinalTime(finalTime);
  	simEMT.setDomain(Domain::EMT);
  	simEMT.addLogger(loggerEMT);
	simEMT.doSystemMatrixRecomputation(true);

	if (useVarResSwitch == true) {
		simEMT.doSystemMatrixRecomputation(true);
	}

	

	if (startFaultEvent){
		auto sw1 = SwitchEvent3Ph::make(startTimeFault, breaker_bus_b_shunt_b_EMT, true);
		simEMT.addEvent(sw1);
		//auto sw2 = SwitchEvent3Ph::make(startTimeFault, breaker_test_EMT, true);
		//simEMT.addEvent(sw2);
	}



	simEMT.run();

}

int main(int argc, char* argv[]) {	
		
/*
	//Simultion parameters
	String simName="scenario_C_step_A";
	Real finalTime = 30;
	Real timeStep = 0.001;
	
	scenario_C_step_A(simName, timeStep, finalTime);
*/

//Simultion parameters
	String simName="scenario_C_step_C";
	Real finalTime = 20;
	Real timeStep = 0.0005;
	Bool startFaultEvent=true;
	Bool endFaultEvent=true;
	Bool useVarResSwitch=false;
	Real startTimeFault=10;
	Real endTimeFault=100;
	Real cmdInertia_G1= 1.0;
	Real cmdDamping_G1= 1.0;


	CommandLineArgs args(argc, argv);
	if (argc > 1) {
		timeStep = args.timeStep;
		finalTime = args.duration;
		if (args.name != "dpsim")
			simName = args.name;
		if (args.options.find("SCALEINERTIA_G1") != args.options.end())
			cmdInertia_G1 = args.getOptionReal("SCALEINERTIA_G1");
		if (args.options.find("SCALEDAMPING_G1") != args.options.end())
			cmdDamping_G1 = args.getOptionReal("SCALEDAMPING_G1");
		if (args.options.find("STARTTIMEFAULT") != args.options.end())
			startTimeFault = args.getOptionReal("STARTTIMEFAULT");
		if (args.options.find("ENDTIMEFAULT") != args.options.end())
			endTimeFault = args.getOptionReal("ENDTIMEFAULT");
		// if (args.options.find("USEVARRESSWITCH") != args.options.end())
		// 	useVarResSwitch = args.options["USEVARRESSWITCH"];	
		// if (args.options.find("FAULTRESISTANCE") != args.options.end())
		// 	SwitchClosed = args.options["FAULTRESISTANCE"];	
	}
	
	scenario_C_step_C(simName, timeStep, finalTime, startFaultEvent, endFaultEvent, startTimeFault, endTimeFault, useVarResSwitch, cmdInertia_G1, cmdDamping_G1);

}