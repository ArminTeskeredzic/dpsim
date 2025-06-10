/* Copyright 2017-2021 Institute for Automation of Complex Power Systems,
 *                     EONERC, RWTH Aachen University
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *********************************************************************************/
#include <DPsim.h>
#include "../Examples.h"
#include "../GeneratorFactory.h"

using namespace DPsim;
using namespace CPS;
using namespace CIM::Examples::Grids::generic_model_B_A;
//using namespace CPS::CIM;

ScenarioConfig generic_model_B_A;
//Examples::Components::SynchronousGeneratorKundur::myMachineParameters
 //syngenKundur;
//Switch to trigger fault at generator terminal
Real SwitchOpen = 1e15;
Real SwitchClosed = 1e-12;
//void scenario_B_step_A(String simName, Real timeStep, Real finalTime){
void scenario_F_step_A_SP(String simName, Real timeStep, Real finalTime, Bool startFaultEvent, Bool endFaultEvent, Real startTimeFault, Real endTimeFault, Bool useVarResSwitch, Real cmdInertia_G1, Real cmdDamping_G1) {
	// ----- POWERFLOW FOR INITIALIZATION -----
	// Real timeStepPF = finalTime;
	// Real finalTimePF = finalTime+timeStepPF;
	// String simNamePF = simName + "_PF";
	// Logger::setLogDir("logs/" + simNamePF);

	// // Components // EDITED ARMIN
	// auto BUS_gas_PF = SimNode<Complex>::make("BUS_gas", PhaseType::Single);
	// auto BUS_b_PF = SimNode<Complex>::make("BUS_b", PhaseType::Single);
	

	// //Synchronous generator 1 // EDITED ARMIN
	// auto GEN_gas_PF = SP::Ph1::SynchronGenerator::make("GEN_gas", Logger::Level::debug);
	// // setPointVoltage is defined as the voltage at the transfomer primary side and should be transformed to network side
	// GEN_gas_PF->setParameters(generic_model_B_A.nomPower_G1, generic_model_B_A.nomPhPhVoltRMS_G1, generic_model_B_A.initActivePower_G1, 10.5e3, PowerflowBusType::VD);
	// GEN_gas_PF->setBaseVoltage(10.5e3);
	
	

	// //Transformer
	// auto TR_gas_PF = std::make_shared<SP::Ph1::Transformer>("TR_gas", Logger::Level::debug);
    // TR_gas_PF->setParameters(generic_model_B_A.nomPhPhVoltRMS_G1/*nomVoltageEnd1*/,  generic_model_B_A.Vnom/*nomVoltageEnd2*/, generic_model_B_A.nomPower_G1 /*ratedPower*/, 
	// 			(generic_model_B_A.nomPhPhVoltRMS_G1/generic_model_B_A.Vnom)/*ratioAbs*/, 0 /*ratioPhase*/, /*2*1.9129660649*/ /*3.64157728*/1.82078864*2 /*resistance*/, 
	// /*2*0.163042774914*/ 0.15518646*2/*0.15518646*2*/ /*inductance*/);
    // //Real baseVolt = voltageNode1 >= voltageNode2 ? voltageNode1 : voltageNode2;
    // TR_gas_PF->setBaseVoltage(generic_model_B_A.Vnom);
	


	// // shunt
	// auto shunt_SR_bcb_PF = SP::Ph1::Shunt::make("shunt_SR_bcb", Logger::Level::debug);
	// shunt_SR_bcb_PF->setParameters(generic_model_B_A.shuntConduntanceB /*conduntance*/, generic_model_B_A.shuntSusceptanceB /*susceptance*/);
	// shunt_SR_bcb_PF->setBaseVoltage(generic_model_B_A.Vnom); // 2.0659e-07 - 2.0659e-05i

	// // auto shunt_SR_bcb_PF = SP::Ph1::Shunt::make("dummy_load_bus_b", Logger::Level::debug);
	// // shunt_SR_bcb_PF->setParameters(0.141312366e6 / std::pow(220e3, 2) /*conduntance*/, 
	// // 								-14.132650562e6 / std::pow(220e3, 2) /*susceptance*/);
	// // shunt_SR_bcb_PF->setBaseVoltage(generic_model_B_A.Vnom); // 2.0659e-07 - 2.0659e-05i


	// //Line1

	// auto line_a_load_PF = SP::Ph1::PiLine::make("breaker_a", Logger::Level::debug);
	// line_a_load_PF->setParameters(1e-8, 1e-5, 0, 1e-15);
	// line_a_load_PF->setBaseVoltage(generic_model_B_A.Vnom);

	// auto line_b_load_PF = SP::Ph1::PiLine::make("breaker_b", Logger::Level::debug);
	// line_b_load_PF->setParameters(1e-8, 1e-5, 0, 1e-15);
	// line_b_load_PF->setBaseVoltage(generic_model_B_A.Vnom);

	// auto dummy_load_bus_psha_PF = SP::Ph1::Load::make("dummy_load_bus_psha", Logger::Level::debug);
	// dummy_load_bus_psha_PF->setParameters(0, 0, 220e3);

	// // auto dummy_load_bus_a_PF = SP::Ph1::Load::make("dummy_load_bus_a", Logger::Level::debug);
	// // dummy_load_bus_a_PF->setParameters(1e-5, 1e-5, 220e3);

	// //auto dummy_load_bus_b_PF = SP::Ph1::Load::make("dummy_load_bus_b", Logger::Level::debug);
	// //dummy_load_bus_b_PF->setParameters(0.141312366e6, 14.132650562e6, 220e3);



	// // Topology
	// GEN_gas_PF->connect({ BUS_gas_PF });
	// TR_gas_PF->connect({ BUS_gas_PF, BUS_b_PF});
	// line_a_load_PF->connect({ BUS_a_PF, BUS_shunt_a_PF});
	// line_b_load_PF->connect({ BUS_b_PF, BUS_shunt_b_PF});
	// shunt_SR_bcb_PF->connect({ BUS_shunt_b_PF });
	// shunt_SR_acb_PF->connect({ BUS_shunt_a_PF });
	// line_3_PF->connect({ BUS_a_PF, BUS_psha_PF});
	// dummy_load_bus_psha_PF->connect({ BUS_psha_PF });
	
	
	// //line_3_PF->connect({ BUS_a_PF, BUS_psha_PF});
	// //dummy_load_bus_psha_PF->connect({ BUS_psha_PF });
	// //dummy_load_bus_a_PF->connect({ BUS_a_PF });
	// //dummy_load_bus_b_PF->connect({ BUS_b_PF });
	// //dummy_load_bus_b_PF->connect({ BUS_b_PF });

	

	// // auto systemPF = SystemTopology(50, // das ist freq??
	// // 		SystemNodeList{BUS_gas_PF, BUS_b_PF, BUS_a_PF, BUS_shunt_a_PF, BUS_shunt_b_PF, BUS_psha_PF},
	// // 		SystemComponentList{GEN_gas_PF, TR_gas_PF, shunt_SR_bcb_PF, shunt_SR_acb_PF, cable_PF, line_a_load_PF, line_b_load_PF, line_3_PF, dummy_load_bus_psha_PF});

	// // small power flow
	// auto systemPF = SystemTopology(50, // das ist freq??
	// 		SystemNodeList{BUS_gas_PF, BUS_b_PF, BUS_a_PF, BUS_shunt_a_PF, BUS_shunt_b_PF, BUS_psha_PF},
	// 		SystemComponentList{GEN_gas_PF, TR_gas_PF, shunt_SR_bcb_PF, shunt_SR_acb_PF, cable_PF, line_a_load_PF, line_b_load_PF, dummy_load_bus_psha_PF, line_3_PF});

	// // Logging
	// auto loggerPF = DataLogger::make(simNamePF);
	// loggerPF->logAttribute("V_BUS_b_PF", BUS_b_PF->attribute("v"));
	// loggerPF->logAttribute("V_BUS_gas_PF", BUS_gas_PF->attribute("v"));

	// // Simulation
	// Simulation simPF(simNamePF, Logger::Level::debug);
	// simPF.setSystem(systemPF);
	// simPF.setTimeStep(timeStepPF);
	// simPF.setFinalTime(finalTimePF);
	// simPF.setDomain(Domain::SP);
	// simPF.setSolverType(Solver::Type::NRP);
	// simPF.setSolverAndComponentBehaviour(Solver::Behaviour::Initialization);
	// simPF.doInitFromNodesAndTerminals(true);
	// simPF.addLogger(loggerPF);
	// simPF.run();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// ----- Dynamic simulation ------
	// String simNameSP = simName + "_SP";
	// Logger::setLogDir("logs/"+simNameSP);

	// // Nodes
	// auto BUS_gas_SP = SimNode<Complex>::make("BUS_gas", PhaseType::Single);
	// auto BUS_a_SP = SimNode<Complex>::make("BUS_a", PhaseType::Single);
	// auto BUS_b_SP = SimNode<Complex>::make("BUS_b", PhaseType::Single);
	// auto BUS_shunt_b_SP = SimNode<Complex>::make("BUS_shunt_b", PhaseType::Single);
	// auto BUS_shunt_a_SP = SimNode<Complex>::make("BUS_shunt_a", PhaseType::Single);
	// auto BUS_psha_SP = SimNode<Complex>::make("BUS_psha", PhaseType::Single);

	// // auto GEN_gas_SP =
    // // 	CPS::SP::Ph1::SynchronGenerator6aOrderVBR::make("GEN_gas", Logger::Level::debug);
 	// // // 	 GEN_gas_EMT->setBaseAndOperationalPerUnitParameters(
    // // //   50e6/*nomPower*/, 10.5e3/*nomVoltage*/, 50/*nomFreq*/,
    // // //   2/*poleNum*/, 1300/*nomFieldCurr*/, 0.002/*Rs*/,
    // // //   2.4/*Ld*/, 1.33 /*Lq*/, 0.31/*Ld_t*/, 1.2/*Lq_t*/,
    // // //   0.24/*Ld_s*/, 0.35/*Lq_s*/, 0.135/*Ll*/, 1.45/*Td0_t*/,
    // // //   0.000001/*Tq0_t*/, 0.022/*Td0_s*/, 0.0095/*Tq0_s*/,
    // // //   5/*H*/);

	// // GEN_gas_SP->setOperationalParametersPerUnit(50e6/*nomPower*/, 10.5e3/*nomVolt*/,
    // //                                    50/*nomFreq*/, 5/*H*/, 2.4/*Ld*/, 1.33/*Lq*/,
    // //                                    0.135/*L0*/, 0.31/*Ld_t*/, 1.2/*Lq_t*/,
    // //                                    1.45/*Td0_t*/, 0.000001/*Tq0_t*/, 0.24/*Ld_s*/,
    // //                                    0.35/*Lq_s*/, 0.022/*Td0_s*/, 0.0095/*Tq0_s*/,
    // //                                    0);
	// // GEN_gas_SP->setInitialValues(Complex (0.3080640628254052e6, -5.041675131002194e6) /*initComplexElectricalPower*/,
    // //                  0.3080640628254052e6 /*initMechanicalPower*/, std::polar (10.5e3, 0.0) /*initTerminalVoltage*/);

	// // GEN_gas_SP->addGovernor(0.3, 7.0, 0.5, 0.3,
    // //                  0.3, 0.4, 20, 0.1,
    // //                  0.3, 0.30880873930480557e6	 / 50e6,
    // //                  0.30880873930480557e6 / 50e6);
	// // 				//  (Real Ta, Real Tb, Real Tc, Real Fa,
    // //                 //                       Real Fb, Real Fc, Real K, Real Tsr,
    // //                 //                       Real Tsm, Real Tm_init, Real PmRef)

    // // GEN_gas_SP->addExciter(0.06, 46, 0.46, -0.0435,
    // //                 1, 0.1, 0.02); // old
	// // GEN_gas_SP->addExciter(1.2, 500, 0.46, -0.0435,
    // //                 1, 0.1, 0.01);
	// 				// (Real Ta, Real Ka, Real Te, Real Ke,
    //                 //                      Real Tf, Real Kf, Real Tr)

	// // 6 order b start
	// auto GEN_gas_SP =
    //  	CPS::SP::Ph1::SynchronGenerator6bOrderVBR::make("GEN_gas", Logger::Level::debug);
	// GEN_gas_SP->setOperationalParametersPerUnit(50e6 /*nomPower*/, 10.5e3 /*Real nomVolt*/,
    //                                    50 /*Real nomFreq*/, 5 /*Real H*/, 2.4 /*Real Ld*/, 1.33 /*Real Lq*/,
    //                                    0.1 /*Real L0*/, 0.31 /*Real Ld_t*/, 1.2 /*Real Lq_t*/,
    //                                    1.45 /*Td0_t*/, 0.000001 /*Real Tq0_t*/, 0.24/*Real Ld_s*/, 
	// 								   0.35/*Real Lq_s*/, 0.022/*Real Td0_s*/, 0.0095/*Real Tq0_s*/, 0/*Real Taa = 0*/);
						   
	// GEN_gas_SP->addExciter(0.01 /*Real Ta*/, 500 /*Real Ka*/, 0.46 /*Real Te*/, -0.0435 /*Real Ke*/,
    //                      1 /*Real Tf*/, 0.1 /*Real Kf*/, 0.01 /*Real Tr*/, 7.65 /*MaxVr*/, -6.5 /*MinVr*/);   
	
	// GEN_gas_SP->addGovernor(0.2 /*Real T3*/, 0.2 /*Real T4*/, 0.2 /*Real T5*/, 0.2 /*Real Tc*/,
    //                  20 /*Real Ts*/, 0.04 /*Real R*/, 0 /*Real Pmin*/, 1 /*Real Pmax*/,
    //                  2*3.14159*50 /*Real OmRef*/, 0.30880800989900337e6 / 50e6 /*Real TmRef*/);

	// GEN_gas_SP->setInitialValues(Complex (0.30880800989900337e6, -5.404225710964056e6),
    //                     0.30880800989900337e6, std::polar (10.5e3, 0.0));

	// // 6 order b end

	// // 4 order begin
	// 	// auto GEN_gas_SP =
    //  	// CPS::SP::Ph1::SynchronGenerator4OrderVBR::make("GEN_gas", Logger::Level::debug);

	// 	// GEN_gas_SP->setOperationalParametersPerUnit(50e6 /*nomPower*/, 10.5e3 /*Real nomVolt*/,
    //     //                                50 /*Real nomFreq*/, 5 /*Real H*/, 2.4 /*Real Ld*/, 1.33 /*Real Lq*/,
    //     //                                0.1 /*Real L0*/, 0.31 /*Real Ld_t*/, 1.2 /*Real Lq_t*/,
    //     //                                1.45 /*Td0_t*/, 0.000001 /*Real Tq0_t*/);

	// 	// GEN_gas_SP->addExciter(0.01 /*Real Ta*/, 500 /*Real Ka*/, 0.46 /*Real Te*/, -0.0435 /*Real Ke*/,
    //     //                  1 /*Real Tf*/, 0.1 /*Real Kf*/, 0.01 /*Real Tr*/, 7.65 /*MaxVr*/, -6.5 /*MinVr*/);

	// 	// GEN_gas_SP->addGovernor(0.2 /*Real T3*/, 0.2 /*Real T4*/, 0.2 /*Real T5*/, 0.2 /*Real Tc*/,
    //     //              20 /*Real Ts*/, 0.04 /*Real R*/, 0 /*Real Pmin*/, 1 /*Real Pmax*/,
    //     //              1 /*Real OmRef*/, 0.30880800989900337e6/50e6 /*Real TmRef*/);

	// // 4 order end

	// //3 order - not working
	// // auto GEN_gas_SP =
    // // 	CPS::SP::Ph1::SynchronGenerator3OrderVBR::make("GEN_gas", Logger::Level::debug);
	// // GEN_gas_SP->setOperationalParametersPerUnit(50e6, 10.5e3,
    // //                                    50, 5, 2.4, 1.33,
    // //                                    0.135, 0.31, 1.2,
    // //                                    1.45, 0.000001);

	// // GEN_gas_SP->setInitialValues(Complex (0.3080640628254052e6, -5.041675131002194e6),
    // //                     0.3080640628254052e6, std::polar (10.5e3, 0.0));

	// // GEN_gas_SP->addExciter(0.06, 46, 0.46, -0.0435,
    // //                  1, 0.1, 0.02);

	// // 3 order end
				 
	// // second order model gen
	// // auto GEN_gas_SP =
    // // 	CPS::SP::Ph1::SynchronGeneratorTrStab::make("GEN_gas", Logger::Level::debug);
	// // GEN_gas_SP->setStandardParametersPU(50e6/*nomPower*/, 10.5e3/*nomVolt*/, 50/*nomFreq*/,
    // //                            0.31/*Xpd*/, 5/*inertia*/, 0.002/*Rs*/, 0/*D*/);
	// // GEN_gas_SP->setInitialValues(Complex (0.30880800989900337e6, -5.404225710964056e6)/*Complex elecPower*/, 0.30880800989900337e6/*Real mechPower*/);
	
	// // voltage source
	// // auto GEN_gas_SP = CPS::SP::Ph1::VoltageSource::make("GEN_gas", Logger::Level::debug);
	// // GEN_gas_SP->setParameters(std::polar (10.5e3, 0.0), 50);

	// // Transformer
	// auto TR_gas_SP = CPS::SP::Ph1::Transformer::make("TR_gas", "TR_gas",
    //                                              Logger::Level::debug, false);
  	// //TR_gas_SP->setParameters(generic_model_B_A.nomPhPhVoltRMS_G1, generic_model_B_A.Vnom, 
    // //                     generic_model_B_A.nomPhPhVoltRMS_G1/generic_model_B_A.Vnom, 0, 1.82078864*2,
    // //                     0.15518646*2);

	// TR_gas_SP->setParameters(generic_model_B_A.nomPhPhVoltRMS_G1/*nomVoltageEnd1*/,  generic_model_B_A.Vnom/*nomVoltageEnd2*/, generic_model_B_A.nomPower_G1 /*ratedPower*/, 
	// 			(generic_model_B_A.nomPhPhVoltRMS_G1/generic_model_B_A.Vnom)/*ratioAbs*/, 0 /*ratioPhase*/, /*2*1.9129660649*/ /*3.64157728*/1.82078864*2 /*resistance*/, 
	// /*2*0.163042774914*/ 0.15518646*2/*0.15518646*2*/ /*inductance*/);
    // //Real baseVolt = voltageNode1 >= voltageNode2 ? voltageNode1 : voltageNode2;
    // TR_gas_SP->setBaseVoltage(generic_model_B_A.Vnom);

	
	// // dummy load
	// auto dummy_load_bus_psha_SP = CPS::SP::Ph1::Load::make("dummy_load_bus_psha", Logger::Level::debug);
	// dummy_load_bus_psha_SP->setParameters(0, 0, 220e3);

	// auto load_shunt_bus_b_SP = CPS::SP::Ph1::Load::make("shunt_SR_bcb", Logger::Level::debug);
	// //load_shunt_bus_b_SP->setParameters(0.1413143604924472e6, 14.131436049245186e6, 220e3);
	// //load_shunt_bus_b_SP->setParameters((0.9706590027527163*220000)*(0.9706590027527163*220000)/(322698.9333), 
	// //								   (0.9706590027527163*220000)*(0.9706590027527163*220000)/(3226.9893), 220e3);
	// load_shunt_bus_b_SP->setParameters((1.0*220000)*(1.0*220000)/(322698.9333), 
	// 								   (1.0*220000)*(1.0*220000)/(3226.9893), 220e3);

	// auto load_shunt_bus_a_SP = CPS::SP::Ph1::Load::make("shunt_SR_acb", Logger::Level::debug);
	// //load_shunt_bus_a_SP->setParameters(0.1413143604924472e6, 14.131436049245186e6, 220e3);
	// //load_shunt_bus_a_SP->setParameters((0.9706590027527163*220000)*(0.9706590027527163*220000)/(322698.9333), 
	// //								   (0.9706590027527163*220000)*(0.9706590027527163*220000)/(3226.9893), 220e3);
	// load_shunt_bus_a_SP->setParameters((1.0*220000)*(1.0*220000)/(322698.9333), 
	// 								   (1.0*220000)*(1.0*220000)/(3226.9893), 220e3);


	// //cable
	// auto cable_SP = CPS::SP::Ph1::PiLine::make("cable", Logger::Level::debug);
	// cable_SP->setParameters(generic_model_B_A.cableResistance /*R/km * km*/, generic_model_B_A.cableInductance /*L/km * km*/, generic_model_B_A.cableCapacitance /*Capacitance*/, generic_model_B_A.cableConductance);
	// cable_SP->setBaseVoltage(generic_model_B_A.Vnom);

	// auto line_3_SP = CPS::SP::Ph1::PiLine::make("line_3", Logger::Level::debug);
	// line_3_SP->setParameters(generic_model_B_A.lineResistance3, generic_model_B_A.lineInductance3, generic_model_B_A.lineCapacitance3, generic_model_B_A.lineConductance3);
	// line_3_SP->setBaseVoltage(generic_model_B_A.Vnom);

	// // switch
	// auto breaker_a_SP = CPS::SP::Ph1::Switch::make("breaker_a", Logger::Level::debug);
	// breaker_a_SP->setParameters(1e12, 1e-8, true);

	// auto breaker_b_SP = CPS::SP::Ph1::Switch::make("breaker_b", Logger::Level::debug);
	// breaker_b_SP->setParameters(1e12, 1e-8, true);


	// // Topology
	// //GEN_gas_SP->connect({BUS_gas_SP, SP::SimNode::GND});
	// GEN_gas_SP->connect({BUS_gas_SP});
	// TR_gas_SP->connect({BUS_gas_SP, BUS_b_SP});
	// cable_SP->connect({BUS_b_SP, BUS_a_SP});
	// breaker_b_SP->connect({BUS_b_SP, BUS_shunt_b_SP});
	// breaker_a_SP->connect({BUS_a_SP, BUS_shunt_a_SP});
	// line_3_SP->connect({BUS_a_SP, BUS_psha_SP});
	// dummy_load_bus_psha_SP->connect({BUS_psha_SP});
	
	// load_shunt_bus_b_SP->connect({BUS_shunt_b_SP});
	// load_shunt_bus_a_SP->connect({BUS_shunt_a_SP});
	// //load_shunt_bus_a_SP->connect({BUS_a_SP});




	// // auto systemSP = SystemTopology(
    // //   50, SystemNodeList{BUS_gas_SP, BUS_a_SP, BUS_b_SP, BUS_shunt_a_SP, BUS_shunt_b_SP, BUS_psha_SP},
    // //   SystemComponentList{GEN_gas_SP, TR_gas_SP, cable_SP, breaker_b_SP, breaker_a_SP, line_3_SP, load_shunt_bus_b_SP, load_shunt_bus_a_SP, dummy_load_bus_psha_SP});

	// for (auto attr : GEN_gas_SP->attributes()) {
    // 	std::string name = attr.first;
    // 	std::cout << name << std::endl;
  	// }


	// auto systemSP = SystemTopology(
    //   50, SystemNodeList{BUS_gas_SP, BUS_b_SP, BUS_a_SP, BUS_shunt_b_SP, BUS_shunt_a_SP, BUS_psha_SP},
    //   SystemComponentList{GEN_gas_SP, TR_gas_SP, load_shunt_bus_b_SP, load_shunt_bus_a_SP, 
	//   					   cable_SP, breaker_b_SP, breaker_a_SP, line_3_SP, dummy_load_bus_psha_SP});

	// systemSP.initWithPowerflow(systemPF, Domain::SP);
	
	// // Logging
	// auto loggerSP = DataLogger::make(simNameSP);

	// loggerSP->logAttribute("v_gen_gas", BUS_gas_SP->attribute("v"));
	// loggerSP->logAttribute("v_bus_b", BUS_b_SP->attribute("v"));
	// //loggerSP->logAttribute("i_gen_gas", GEN_gas_SP->attribute("i_intf"));
	// //loggerSP->logAttribute("v3", n3SP->attribute("v"));
	// //loggerSP->logAttribute("P_mech1", GEN_gas_SP->attribute("P_mech"));
	// //loggerSP->logAttribute("P_elec1", GEN_gas_SP->attribute("P_elec"));
	// // loggerSP->logAttribute("GEN_gas_SP_v", GEN_gas_SP->attribute("v_intf"));
	// // loggerSP->logAttribute("S", TR_gas_SP->attribute("S"));
	
	





	// Simulation simSP(simNameSP, Logger::Level::debug);
	// simSP.doInitFromNodesAndTerminals(true);
	// simSP.setSystem(systemSP);
	// simSP.setTimeStep(timeStep);
	// simSP.setFinalTime(finalTime);
	// simSP.setDomain(Domain::SP);
	// simSP.addLogger(loggerSP);
    // simSP.doSystemMatrixRecomputation(true);

	// if (useVarResSwitch == true) {
	// 	simSP.doSystemMatrixRecomputation(true);
	// }

	// if (startFaultEvent){
	// 	auto sw1 = SwitchEvent::make(startTimeFault, breaker_b_SP, false);
	// 	auto sw2 = SwitchEvent::make(startTimeFault, breaker_a_SP, false);
	// 	simSP.addEvent(sw1);
	// 	simSP.addEvent(sw2);
	// }

	// simSP.run();


}


void scenario_F_step_A_EMT(String simName, Real timeStep, Real finalTime, Bool startFaultEvent, Bool endFaultEvent, Real startTimeFault, Real endTimeFault, Bool useVarResSwitch, Real cmdInertia_G1, Real cmdDamping_G1) {
	// ----- POWERFLOW FOR INITIALIZATION -----
	Real timeStepPF = finalTime;
	Real finalTimePF = finalTime+timeStepPF;
	String simNamePF = simName + "_PF";
	Logger::setLogDir("logs/" + simNamePF);

	// Components // EDITED ARMIN
	auto BUS_gas_PF = SimNode<Complex>::make("BUS_gas", PhaseType::Single);
	auto BUS_b_PF = SimNode<Complex>::make("BUS_b", PhaseType::Single);
	auto BUS_c_PF = SimNode<Complex>::make("BUS_c", PhaseType::Single);
	auto BUS_coal_PF = SimNode<Complex>::make("BUS_coal", PhaseType::Single);
	auto BUS_gen_coal_PF = SimNode<Complex>::make("BUS_gen_coal", PhaseType::Single);
	auto BUS_tr_aux_PF = SimNode<Complex>::make("BUS_tr_aux", PhaseType::Single);
	auto BUS_load_PF = SimNode<Complex>::make("BUS_load", PhaseType::Single);


	//Synchronous generator 1 // EDITED ARMIN
	auto GEN_gas_PF = SP::Ph1::SynchronGenerator::make("GEN_gas", Logger::Level::debug);
	// setPointVoltage is defined as the voltage at the transfomer primary side and should be transformed to network side
	GEN_gas_PF->setParameters(generic_model_B_A.nomPower_G1, generic_model_B_A.nomPhPhVoltRMS_G1, 
							generic_model_B_A.initActivePower_G1, 10.5e3, PowerflowBusType::VD);
	GEN_gas_PF->setBaseVoltage(10.5e3);
	
	auto GEN_coal_PF = SP::Ph1::SynchronGenerator::make("GEN_coal", Logger::Level::debug);
	// setPointVoltage is defined as the voltage at the transfomer primary side and should be transformed to network side
	GEN_coal_PF->setParameters(600.0e6 /*Real ratedApparentPower*/, 21.0e3 /*Real ratedVoltage*/, 
							0 /*Real setPointActivePower*/, 
							21.0e3 /*Real setPointVoltage*/, PowerflowBusType::PV);
	GEN_coal_PF->setBaseVoltage(21.0e3);



	//Transformer
	auto TR_gas_PF = std::make_shared<SP::Ph1::Transformer>("TR_gas", Logger::Level::debug);
    TR_gas_PF->setParameters(generic_model_B_A.nomPhPhVoltRMS_G1/*nomVoltageEnd1*/,  generic_model_B_A.Vnom/*nomVoltageEnd2*/, generic_model_B_A.nomPower_G1 /*ratedPower*/, 
				(generic_model_B_A.nomPhPhVoltRMS_G1/generic_model_B_A.Vnom)/*ratioAbs*/, 0 /*ratioPhase*/, 1.82078864*2 /*resistance*/, 
				 0.15518646*2 /*inductance*/);
    TR_gas_PF->setBaseVoltage(generic_model_B_A.Vnom);
	

	auto TR_coal_PF = std::make_shared<SP::Ph1::Transformer>("TR_coal", Logger::Level::debug);
    TR_coal_PF->setParameters(21e3/*nomVoltageEnd1*/,  400e3/*nomVoltageEnd2*/, 600e6 /*ratedPower*/, 
				((21e3)/(400e3))/*ratioAbs*/, 0 /*ratioPhase*/, 0.2910666667*2 /*resistance*/, 
				0.0636552829*2 /*inductance*/);
    TR_coal_PF->setBaseVoltage(400e3);

	auto TR1_bc_PF = std::make_shared<SP::Ph1::Transformer>("TR1_bc", Logger::Level::debug);
    TR1_bc_PF->setParameters(220e3/*nomVoltageEnd1*/,  400e3/*nomVoltageEnd2*/, 300e6 /*ratedPower*/, 
				((220e3)/(400e3))/*ratioAbs*/, 0 /*ratioPhase*/, 1.33333333333*2 /*resistance*/, 
				0.1004964577384912*2 /*inductance*/);
    TR1_bc_PF->setBaseVoltage(400e3);

	auto TR_aux_PF = std::make_shared<SP::Ph1::Transformer>("TR_aux", Logger::Level::debug);
    TR_aux_PF->setParameters(10.5e3/*nomVoltageEnd1*/,  21.0e3/*nomVoltageEnd2*/, 60e6 /*ratedPower*/, 
				((10.5e3)/(21.0e3))/*ratioAbs*/, 0 /*ratioPhase*/, 0.0107898*2 /*resistance*/, 
				0.0012043933724643*2 /*inductance*/);
    //Real baseVolt = voltageNode1 >= voltageNode2 ? voltageNode1 : voltageNode2;
    TR_aux_PF->setBaseVoltage(21.0e3);


	// load
	auto LOAD_aux_PF = SP::Ph1::Load::make("LOAD_aux",  Logger::Level::debug);
	LOAD_aux_PF->setParameters(0e6 /*Real activePower W*/, 0e6 /*Real reactivePower*/, 
								10.5e3 /*Real nominalVoltage*/);
	// 4.0e6, 1.3e6


	//Line1

	auto line_GEN_coal_PF = SP::Ph1::PiLine::make("breaker_GEN_coal", Logger::Level::debug);
	line_GEN_coal_PF->setParameters(1e19, 1e-5, 0, 1e-15);
	line_GEN_coal_PF->setBaseVoltage(21e3);

	auto line_BUS_tr_aux_PF = SP::Ph1::PiLine::make("breaker_tr_aux", Logger::Level::debug);
	line_BUS_tr_aux_PF->setParameters(1e-5, 1e-5, 0, 1e-5);
	line_BUS_tr_aux_PF->setBaseVoltage(21e3);

	auto dummy_load_bus_c_PF = SP::Ph1::Load::make("dummy_load_bus_c", Logger::Level::debug);
	dummy_load_bus_c_PF->setParameters(0e6, 0e6, 400e3);

	auto dummy_load_bus_coal_PF = SP::Ph1::Load::make("dummy_load_bus_coal", Logger::Level::debug);
	dummy_load_bus_coal_PF->setParameters(4e6, 1.3e6, 21e3);

	auto dummy_load_bus_b_PF = SP::Ph1::Load::make("dummy_load_bus_b", Logger::Level::debug);
	dummy_load_bus_b_PF->setParameters(0, 0, 220e3);

	// Line/breakers



	// Topology
	GEN_gas_PF->connect({ BUS_gas_PF });
	TR_gas_PF->connect({ BUS_gas_PF, BUS_b_PF});
	TR1_bc_PF->connect({ BUS_b_PF, BUS_c_PF});
	TR_coal_PF->connect({ BUS_coal_PF, BUS_c_PF});
	//line_GEN_coal_PF->connect({ BUS_coal_PF, BUS_gen_coal_PF});
	line_BUS_tr_aux_PF->connect({BUS_tr_aux_PF, BUS_coal_PF});
	TR_aux_PF->connect({ BUS_load_PF, BUS_tr_aux_PF});
	LOAD_aux_PF->connect({ BUS_load_PF });
	//GEN_coal_PF->connect({ BUS_gen_coal_PF });
	//dummy_load_bus_b_PF->connect({ BUS_b_PF });
	
	//line_3_PF->connect({ BUS_a_PF, BUS_psha_PF});
	//dummy_load_bus_c_PF->connect({ BUS_c_PF });
	//dummy_load_bus_a_PF->connect({ BUS_a_PF });
	//dummy_load_bus_b_PF->connect({ BUS_b_PF });
	//dummy_load_bus_b_PF->connect({ BUS_b_PF });

	// dummy_load_bus_psha_PF->connect({ BUS_b_PF });
	// dummy_load_bus_psh_PF->connect({ BUS_c_PF });
	//dummy_load_bus_coal_PF->connect({ BUS_coal_PF });


	
	auto systemPF = SystemTopology(50, // das ist freq??
			SystemNodeList{BUS_gas_PF, BUS_b_PF, BUS_c_PF, BUS_coal_PF, BUS_load_PF, BUS_tr_aux_PF},
			SystemComponentList{GEN_gas_PF, TR_gas_PF, TR1_bc_PF, TR_coal_PF, TR_aux_PF, LOAD_aux_PF, line_BUS_tr_aux_PF});
	
	// auto systemPF = SystemTopology(50, // das ist freq??
	// 		SystemNodeList{BUS_gas_PF, BUS_b_PF, BUS_c_PF, BUS_coal_PF, BUS_gen_coal_PF, BUS_tr_aux_PF, BUS_load_PF},
	// 		SystemComponentList{GEN_gas_PF, GEN_coal_PF, TR_gas_PF, TR1_bc_PF, TR_coal_PF, line_GEN_coal_PF, line_BUS_tr_aux_PF, TR_aux_PF, LOAD_aux_PF });

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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// ----- Dynamic simulation ------
	String simNameEMT = simName + "_EMT";
	Logger::setLogDir("logs/"+simNameEMT);

	// Nodes
	auto BUS_gas_EMT = SimNode<Real>::make("BUS_gas", PhaseType::ABC);
	auto BUS_b_EMT = SimNode<Real>::make("BUS_b", PhaseType::ABC);
	auto BUS_c_EMT = SimNode<Real>::make("BUS_c", PhaseType::ABC);
	auto BUS_coal_EMT = SimNode<Real>::make("BUS_coal", PhaseType::ABC);
	auto BUS_gen_coal_EMT = SimNode<Real>::make("BUS_gen_coal", PhaseType::ABC);
	auto BUS_tr_aux_EMT = SimNode<Real>::make("BUS_tr_aux", PhaseType::ABC);
	auto BUS_load_EMT = SimNode<Real>::make("BUS_load", PhaseType::ABC);


	// Components

	// generator 6 order - working myb - odavde
	auto GEN_gas_EMT =
      CPS::EMT::Ph3::SynchronGeneratorVBR::make("GEN_gas", Logger::Level::debug);
 		 GEN_gas_EMT->setBaseAndOperationalPerUnitParameters(
      50e6/*nomPower*/, 10.5e3/*nomVoltage*/, 50/*nomFreq*/,
      2/*poleNum*/, 1300/*nomFieldCurr*/, 0.002/*Rs*/,
      2.4/*Ld*/, 1.33 /*Lq*/, 0.31/*Ld_t*/, 1.2/*Lq_t*/,
      0.24/*Ld_s*/, 0.35/*Lq_s*/, 0.135/*Ll*/, 1.45/*Td0_t*/,
      0.000001/*Tq0_t*/, 0.022/*Td0_s*/, 0.0095/*Tq0_s*/,
      5/*H*/);

	//   GEN_gas_EMT->setInitialValues(0.30880873930480557e6, -5.404225710964056e6, 1,
    //                     0, 0.30880873930480557e6);

	// ovaj governor radi koliko-toliko
	GEN_gas_EMT->addGovernor(0.3 /*Real Ta 0.3*/, 12.0 /*Real Tb 7.0*/, 0.5 /*Real Tc 0.5*/, 0.3 /*0.33 Real Fa 0.3*/,
                     0.3 /*0.065 Real Fb 0.3*/, 0.4 /*0.055 Real Fc 0.4*/, 20 /*Real K 20*/, 0.1 /*Real Tsr 0.1*/,
                     0.3 /*Real Tsm 0.3*/,  0.004409998144378591e6 / 50e6 /*Real Tm_init*/,
                       0.004409998144378591e6 / 50e6 /*Real PmRef*/);
					//  (Real Ta, Real Tb, Real Tc, Real Fa,
                    //                       Real Fb, Real Fc, Real K, Real Tsr,
                    //                       Real Tsm, Real Tm_init, Real PmRef)
	//4.002589142073939


    // GEN_gas_EMT->addExciter(0.06, 46, 0.46, -0.0435,
    //                 1, 0.1, 0.02); // old
	// GEN_gas_EMT->addExciter(0.02, 500, 0.46, -0.0435,
    //                 1, 0.1, 0.01);
					// (Real Ta, Real Ka, Real Te, Real Ke,
                    //                      Real Tf, Real Kf, Real Tr)
	// second exciter parameters
	GEN_gas_EMT->addExciter(0.01 /*Real Ta*/, 500 /*Real Ka*/, 0.46 /*Real Te*/, 0.0435 /*Real Ke*/,
                         1 /*Real Tf*/, 0.1 /*Real Kf*/, 0.01 /*Real Tr*/, 7.65 /*MaxVr*/, -6.5 /*MinVr*/);
	
	//GEN_gas_EMT->setInitialValues(3.960690276e6/50e6, 1.413428232e6/50e6, 1, 0, 3.960690276e6/50e6);

	// generator 6 order dovde

	auto GEN_coal_EMT =
      CPS::EMT::Ph3::SynchronGeneratorVBR::make("GEN_coal", Logger::Level::debug);
 		 GEN_coal_EMT->setBaseAndOperationalPerUnitParameters(
      600e6/*nomPower*/, 21e3/*nomVoltage*/, 50/*nomFreq*/,
      2/*poleNum*/, 1300/*nomFieldCurr*/, 0.001/*Rs*/,
      2.23/*Ld*/, 1.9 /*Lq*/, 0.365/*Ld_t*/, 0.785/*Lq_t*/,
      0.268/*Ld_s*/, 0.268/*Lq_s*/, 0.224/*Ll*/, 1.267/*Td0_t*/,
      1.15/*Tq0_t*/, 0.034/*Td0_s*/, 0.074/*Tq0_s*/,
      5.22/*H*/);

	// ovaj governor radi koliko-toliko
	GEN_coal_EMT->addGovernor(0.3 /*Real Ta 0.3*/, 12.0 /*Real Tb 7.0*/, 0.5 /*Real Tc 0.5*/, 0.3 /*0.33 Real Fa 0.3*/,
                     0.3 /*0.065 Real Fb 0.3*/, 0.4 /*0.055 Real Fc 0.4*/, 20 /*Real K 20*/, 0.1 /*Real Tsr 0.1*/,
                     0.3 /*Real Tsm 0.3*/, 0.0 / 600e6 /*Real Tm_init*/,
                     0.0 / 600e6 /*Real PmRef*/);
					//  (Real Ta, Real Tb, Real Tc, Real Fa,
                    //                       Real Fb, Real Fc, Real K, Real Tsr,
                    //                       Real Tsm, Real Tm_init, Real PmRef)


    // GEN_gas_EMT->addExciter(0.06, 46, 0.46, -0.0435,
    //                 1, 0.1, 0.02); // old
	// GEN_gas_EMT->addExciter(0.02, 500, 0.46, -0.0435,
    //                 1, 0.1, 0.01);
					// (Real Ta, Real Ka, Real Te, Real Ke,
                    //                      Real Tf, Real Kf, Real Tr)
	// second exciter parameters
	GEN_coal_EMT->addExciter(0.01 /*Real Ta*/, 500 /*Real Ka*/, 0.46 /*Real Te*/, 0.0435 /*Real Ke*/,
                         1 /*Real Tf*/, 0.1 /*Real Kf*/, 0.01 /*Real Tr*/, 7.65 /*MaxVr*/, -6.5 /*MinVr*/);

	//GEN_coal_EMT->setInitialValues(0, 0, 1, 0, 0);

	// Trafo
	auto TR_gas_EMT = EMT::Ph3::Transformer::make("TR_gas", "TR_gas", Logger::Level::debug, true);
	TR_gas_EMT->setParameters(generic_model_B_A.nomPhPhVoltRMS_G1, generic_model_B_A.Vnom, generic_model_B_A.nomPower_G1,
                     (generic_model_B_A.nomPhPhVoltRMS_G1/generic_model_B_A.Vnom), 0, Math::singlePhaseParameterToThreePhase(1.82078864*2),
                     Math::singlePhaseParameterToThreePhase(0.15518646*2));

	auto TR_coal_EMT = EMT::Ph3::Transformer::make("TR_coal", "TR_coal", Logger::Level::debug, true);
	TR_coal_EMT->setParameters(21e3, 400e3, 600e6 ,
                     (21e3/400e3), 0, Math::singlePhaseParameterToThreePhase(0.2910666667*2),
                     Math::singlePhaseParameterToThreePhase(0.0636552829*2));

	auto TR1_bc_EMT = EMT::Ph3::Transformer::make("TR1_bc", "TR1_bc", Logger::Level::debug, true);
	TR1_bc_EMT->setParameters(220e3, 400e3, 300e6,
                     (220e3/400e3), 0, Math::singlePhaseParameterToThreePhase(1.33333333333*2),
                     Math::singlePhaseParameterToThreePhase(0.1004964577384912*2));

	auto TR_aux_EMT = EMT::Ph3::Transformer::make("TR_aux", "TR_aux", Logger::Level::debug, true);
	TR_aux_EMT->setParameters(10.5e3, 21e3, 60e6,
                     (10.5e3/21e3), 0, Math::singlePhaseParameterToThreePhase(0.0107898*2),
                     Math::singlePhaseParameterToThreePhase(0.0012043933724643*2));
	

	// Load
	auto LOAD_aux_EMT = EMT::Ph3::RXLoad::make("LOAD_aux", Logger::Level::debug);
	LOAD_aux_EMT->setParameters(CPS::Math::singlePhasePowerToThreePhase(8e6), 
	CPS::Math::singlePhasePowerToThreePhase(1.3e6), 10.5e3);
	// 4e6, 1.3e6
	

	// Cable
	// auto cable_EMT = EMT::Ph3::PiLine::make("cable", Logger::Level::debug);
	// cable_EMT->setParameters(Math::singlePhaseParameterToThreePhase(generic_model_B_A.cableResistance), 
	//                       Math::singlePhaseParameterToThreePhase(generic_model_B_A.cableInductance), 
	// 				      Math::singlePhaseParameterToThreePhase(generic_model_B_A.cableCapacitance),
	// 					  Math::singlePhaseParameterToThreePhase(generic_model_B_A.cableConductance));

	// // Line3
	// auto line3_EMT = EMT::Ph3::PiLine::make("line_3", Logger::Level::debug);
	// line3_EMT->setParameters(Math::singlePhaseParameterToThreePhase(generic_model_B_A.lineResistance3), 
	//                       Math::singlePhaseParameterToThreePhase(generic_model_B_A.lineInductance3), 
	// 				      Math::singlePhaseParameterToThreePhase(generic_model_B_A.lineCapacitance3),
	// 					  Math::singlePhaseParameterToThreePhase(generic_model_B_A.lineConductance3));



	// Switch
	auto breaker_GEN_coal_EMT = CPS::EMT::Ph3::Switch::make("breaker_GEN_coal", Logger::Level::debug);
	breaker_GEN_coal_EMT->setParameters(Math::singlePhaseParameterToThreePhase(SwitchOpen), 
							Math::singlePhaseParameterToThreePhase(SwitchClosed));
	breaker_GEN_coal_EMT->openSwitch();

	auto breaker_tr_aux_EMT = CPS::EMT::Ph3::Switch::make("breaker_tr_aux", Logger::Level::debug);
	breaker_tr_aux_EMT->setParameters(Math::singlePhaseParameterToThreePhase(SwitchOpen), 
							Math::singlePhaseParameterToThreePhase(SwitchClosed));
	breaker_tr_aux_EMT->openSwitch();


	
	auto dummy_load_bus_c_EMT = EMT::Ph3::RXLoad::make("dummy_load_bus_c", Logger::Level::debug);
	dummy_load_bus_c_EMT->setParameters(CPS::Math::singlePhasePowerToThreePhase(0e3), 
	CPS::Math::singlePhasePowerToThreePhase(0e3), 400e3);

	auto dummy_load_bus_coal_EMT = EMT::Ph3::RXLoad::make("dummy_load_bus_coal", Logger::Level::debug);
	dummy_load_bus_coal_EMT->setParameters(CPS::Math::singlePhasePowerToThreePhase(0e3), 
	CPS::Math::singlePhasePowerToThreePhase(0e3), 21e3);

	auto dummy_load_bus_b_EMT = EMT::Ph3::RXLoad::make("dummy_load_bus_b", Logger::Level::debug);
	dummy_load_bus_b_EMT->setParameters(CPS::Math::singlePhasePowerToThreePhase(0e3), 
	CPS::Math::singlePhasePowerToThreePhase(0e3), 220e3);

	

	// Topology
	auto vs = EMT::Ph3::VoltageSource::make("GEN_gas", Logger::Level::debug);
  	vs->setParameters(
      CPS::Math::singlePhaseVariableToThreePhase(CPS::Math::polar(10.5e3, 0)),
      50);

	//vs->connect({ BUS_gas_EMT, SimNode<Real>::GND });
	GEN_gas_EMT->connect({ BUS_gas_EMT });
	TR_gas_EMT->connect({ BUS_gas_EMT, BUS_b_EMT});
	TR1_bc_EMT->connect({ BUS_b_EMT, BUS_c_EMT});
	TR_coal_EMT->connect({ BUS_coal_EMT, BUS_c_EMT});

	breaker_tr_aux_EMT->connect({BUS_tr_aux_EMT, BUS_coal_EMT});
	TR_aux_EMT->connect({ BUS_load_EMT, BUS_tr_aux_EMT});
	LOAD_aux_EMT->connect({ BUS_load_EMT });

	breaker_GEN_coal_EMT->connect({ BUS_gen_coal_EMT, BUS_coal_EMT});
	GEN_coal_EMT->connect({ BUS_gen_coal_EMT });

	
	

	auto systemEMT = SystemTopology(50,
			SystemNodeList{BUS_gas_EMT, BUS_b_EMT, BUS_c_EMT, BUS_coal_EMT, BUS_load_EMT, BUS_tr_aux_EMT, BUS_gen_coal_EMT},
			SystemComponentList{GEN_gas_EMT, TR_gas_EMT, TR1_bc_EMT, TR_coal_EMT, TR_aux_EMT, LOAD_aux_EMT, breaker_tr_aux_EMT, breaker_GEN_coal_EMT});

	// Initialization of dynamic topology
	systemEMT.initWithPowerflow(systemPF, Domain::EMT);

	for (auto attr : GEN_gas_EMT->attributes()) {
    	std::string name = attr.first;
    	std::cout << name << std::endl;
  	}


	// Logging
	auto loggerEMT = DataLogger::make(simNameEMT);
	loggerEMT->logAttribute("BUS_gas_EMT_v", BUS_gas_EMT->attribute("v"));
	loggerEMT->logAttribute("BUS_b_EMT_v", BUS_b_EMT->attribute("v"));
	loggerEMT->logAttribute("BUS_c_EMT_v", BUS_c_EMT->attribute("v"));
	loggerEMT->logAttribute("BUS_coal_EMT_v", BUS_coal_EMT->attribute("v"));
	loggerEMT->logAttribute("BUS_tr_aux_EMT_v", BUS_tr_aux_EMT->attribute("v"));
	loggerEMT->logAttribute("BUS_load_EMT_v", BUS_load_EMT->attribute("v"));

	loggerEMT->logAttribute("GEN_gas_EMT_w_r", GEN_gas_EMT->attribute("w_r"));
	loggerEMT->logAttribute("GEN_gas_EMT_P_elec", GEN_gas_EMT->attribute("P_elec"));
	loggerEMT->logAttribute("GEN_gas_EMT_Q_elec", GEN_gas_EMT->attribute("Q_elec"));
	loggerEMT->logAttribute("GEN_gas_EMT_P_mech", GEN_gas_EMT->attribute("P_mech"));
	loggerEMT->logAttribute("GEN_gas_EMT_i_intf", GEN_gas_EMT->attribute("i_intf"));
	loggerEMT->logAttribute("GEN_gas_EMT_v_intf", GEN_gas_EMT->attribute("v_intf"));
	loggerEMT->logAttribute("GEN_gas_EMT_delta_r", GEN_gas_EMT->attribute("delta_r"));
	loggerEMT->logAttribute("GEN_gas_EMT_T_e", GEN_gas_EMT->attribute("T_e"));

	loggerEMT->logAttribute("GEN_coal_EMT_w_r", GEN_coal_EMT->attribute("w_r"));
	loggerEMT->logAttribute("GEN_coal_EMT_P_elec", GEN_coal_EMT->attribute("P_elec"));
	loggerEMT->logAttribute("GEN_coal_EMT_Q_elec", GEN_coal_EMT->attribute("Q_elec"));
	loggerEMT->logAttribute("GEN_coal_EMT_P_mech", GEN_coal_EMT->attribute("P_mech"));
	loggerEMT->logAttribute("GEN_coal_EMT_i_intf", GEN_coal_EMT->attribute("i_intf"));
	loggerEMT->logAttribute("GEN_coal_EMT_v_intf", GEN_coal_EMT->attribute("v_intf"));
	loggerEMT->logAttribute("GEN_coal_EMT_delta_r", GEN_coal_EMT->attribute("delta_r"));
	loggerEMT->logAttribute("GEN_coal_EMT_T_e", GEN_coal_EMT->attribute("T_e"));



	//loggerEMT->logAttribute("GEN_gas_EMT_ep_mag", GEN_gas_EMT->attribute("Ep_mag"));
	// loggerEMT->logAttribute("GEN_gas_EMT_v", GEN_gas_EMT->attribute("v_intf"));
	// loggerEMT->logAttribute("GEN_gas_EMT_i", GEN_gas_EMT->attribute("i_intf"));
	// loggerEMT->logAttribute("GEN_gas_EMT_wr", GEN_gas_EMT->attribute("w_r"));
	// loggerEMT->logAttribute("GEN_gas_EMT_delta", GEN_gas_EMT->attribute("delta_r"));	
	//loggerEMT->logAttribute("P_mech1", GEN_gas_EMT->attribute("P_mech"));
	//loggerEMT->logAttribute("P_elec1", GEN_gas_EMT->attribute("P_elec"));
	

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
		auto sw1 = SwitchEvent3Ph::make(startTimeFault, breaker_tr_aux_EMT, true);
		simEMT.addEvent(sw1);
		GEN_coal_EMT->setInitialValues(4e6/600e6, 1e6/600e6, 1, 0, 4e6/600e6);
		auto sw2 = SwitchEvent3Ph::make(startTimeFault + 5, breaker_GEN_coal_EMT, true);
		simEMT.addEvent(sw2);
	}


	simEMT.run();

}



void scenario_F_step_A_DP(String simName, Real timeStep, Real finalTime, Bool startFaultEvent, Bool endFaultEvent, Real startTimeFault, Real endTimeFault, Bool useVarResSwitch, Real cmdInertia_G1, Real cmdDamping_G1) {
	// ----- POWERFLOW FOR INITIALIZATION -----
	Real timeStepPF = finalTime;
	Real finalTimePF = finalTime+timeStepPF;
	String simNamePF = simName + "_PF";
	Logger::setLogDir("logs/" + simNamePF);

	// Components // EDITED ARMIN
	auto BUS_gas_PF = SimNode<Complex>::make("BUS_gas", PhaseType::Single);
	auto BUS_a_PF = SimNode<Complex>::make("BUS_a", PhaseType::Single);
	auto BUS_b_PF = SimNode<Complex>::make("BUS_b", PhaseType::Single);
	auto BUS_shunt_b_PF = SimNode<Complex>::make("BUS_shunt_b", PhaseType::Single);
	auto BUS_shunt_a_PF = SimNode<Complex>::make("BUS_shunt_a", PhaseType::Single);
	auto BUS_psha_PF = SimNode<Complex>::make("BUS_psha", PhaseType::Single);

	//Synchronous generator 1 // EDITED ARMIN
	auto GEN_gas_PF = SP::Ph1::SynchronGenerator::make("GEN_gas", Logger::Level::debug);
	// setPointVoltage is defined as the voltage at the transfomer primary side and should be transformed to network side
	GEN_gas_PF->setParameters(generic_model_B_A.nomPower_G1, generic_model_B_A.nomPhPhVoltRMS_G1, generic_model_B_A.initActivePower_G1, 10.5e3, PowerflowBusType::VD);
	GEN_gas_PF->setBaseVoltage(10.5e3);
	
	

	//Transformer
	auto TR_gas_PF = std::make_shared<SP::Ph1::Transformer>("TR_gas", Logger::Level::debug);
    TR_gas_PF->setParameters(generic_model_B_A.nomPhPhVoltRMS_G1/*nomVoltageEnd1*/,  generic_model_B_A.Vnom/*nomVoltageEnd2*/, generic_model_B_A.nomPower_G1 /*ratedPower*/, 
				(generic_model_B_A.nomPhPhVoltRMS_G1/generic_model_B_A.Vnom)/*ratioAbs*/, 0 /*ratioPhase*/, /*2*1.9129660649*/ /*3.64157728*/1.82078864*2 /*resistance*/, 
	/*2*0.163042774914*/ 0.15518646*2/*0.15518646*2*/ /*inductance*/);
    //Real baseVolt = voltageNode1 >= voltageNode2 ? voltageNode1 : voltageNode2;
    TR_gas_PF->setBaseVoltage(generic_model_B_A.Vnom);
	
	

	// shunt
	auto shunt_SR_bcb_PF = SP::Ph1::Shunt::make("shunt_SR_bcb", Logger::Level::debug);
	shunt_SR_bcb_PF->setParameters(generic_model_B_A.shuntConduntanceB /*conduntance*/, generic_model_B_A.shuntSusceptanceB /*susceptance*/);
	shunt_SR_bcb_PF->setBaseVoltage(generic_model_B_A.Vnom); // 2.0659e-07 - 2.0659e-05i

	// auto shunt_SR_bcb_PF = SP::Ph1::Shunt::make("dummy_load_bus_b", Logger::Level::debug);
	// shunt_SR_bcb_PF->setParameters(0.141312366e6 / std::pow(220e3, 2) /*conduntance*/, 
	// 								-14.132650562e6 / std::pow(220e3, 2) /*susceptance*/);
	// shunt_SR_bcb_PF->setBaseVoltage(generic_model_B_A.Vnom); // 2.0659e-07 - 2.0659e-05i

	

	auto shunt_SR_acb_PF = SP::Ph1::Shunt::make("shunt_SR_acb", Logger::Level::debug);
	shunt_SR_acb_PF->setParameters(generic_model_B_A.shuntConduntanceA /*conduntance*/, generic_model_B_A.shuntSusceptanceA /*susceptance*/);
	shunt_SR_acb_PF->setBaseVoltage(generic_model_B_A.Vnom); // 2.0659e-07 - 2.0659e-05i

	//Line1
	auto cable_PF = SP::Ph1::PiLine::make("cable", Logger::Level::debug);
	cable_PF->setParameters(generic_model_B_A.cableResistance /*R/km * km*/, generic_model_B_A.cableInductance /*L/km * km*/, generic_model_B_A.cableCapacitance /*Capacitance*/, generic_model_B_A.cableConductance);
	cable_PF->setBaseVoltage(generic_model_B_A.Vnom);
	
	auto line_3_PF = SP::Ph1::PiLine::make("line_3", Logger::Level::debug);
	line_3_PF->setParameters(generic_model_B_A.lineResistance3, generic_model_B_A.lineInductance3, generic_model_B_A.lineCapacitance3, generic_model_B_A.lineConductance3);
	line_3_PF->setBaseVoltage(generic_model_B_A.Vnom);

	auto line_a_load_PF = SP::Ph1::PiLine::make("breaker_a", Logger::Level::debug);
	line_a_load_PF->setParameters(1e-8, 1e-5, 0, 1e-15);
	line_a_load_PF->setBaseVoltage(generic_model_B_A.Vnom);

	auto line_b_load_PF = SP::Ph1::PiLine::make("breaker_b", Logger::Level::debug);
	line_b_load_PF->setParameters(1e-8, 1e-5, 0, 1e-15);
	line_b_load_PF->setBaseVoltage(generic_model_B_A.Vnom);

	auto dummy_load_bus_psha_PF = SP::Ph1::Load::make("dummy_load_bus_psha", Logger::Level::debug);
	dummy_load_bus_psha_PF->setParameters(0, 0, 220e3);

	

	// auto dummy_load_bus_a_PF = SP::Ph1::Load::make("dummy_load_bus_a", Logger::Level::debug);
	// dummy_load_bus_a_PF->setParameters(1e-5, 1e-5, 220e3);

	//auto dummy_load_bus_b_PF = SP::Ph1::Load::make("dummy_load_bus_b", Logger::Level::debug);
	//dummy_load_bus_b_PF->setParameters(0.141312366e6, 14.132650562e6, 220e3);



	// Topology
	GEN_gas_PF->connect({ BUS_gas_PF });
	TR_gas_PF->connect({ BUS_gas_PF, BUS_b_PF});
	cable_PF->connect({ BUS_b_PF, BUS_a_PF});
	line_a_load_PF->connect({ BUS_a_PF, BUS_shunt_a_PF});
	line_b_load_PF->connect({ BUS_b_PF, BUS_shunt_b_PF});
	shunt_SR_bcb_PF->connect({ BUS_shunt_b_PF });
	shunt_SR_acb_PF->connect({ BUS_shunt_a_PF });
	dummy_load_bus_psha_PF->connect({ BUS_psha_PF });
	line_3_PF->connect({ BUS_a_PF, BUS_psha_PF});
	
	//line_3_PF->connect({ BUS_a_PF, BUS_psha_PF});
	//dummy_load_bus_psha_PF->connect({ BUS_psha_PF });
	//dummy_load_bus_a_PF->connect({ BUS_a_PF });
	//dummy_load_bus_b_PF->connect({ BUS_b_PF });
	//dummy_load_bus_b_PF->connect({ BUS_b_PF });

	

	// auto systemPF = SystemTopology(50, // das ist freq??
	// 		SystemNodeList{BUS_gas_PF, BUS_b_PF, BUS_a_PF, BUS_shunt_a_PF, BUS_shunt_b_PF, BUS_psha_PF},
	// 		SystemComponentList{GEN_gas_PF, TR_gas_PF, shunt_SR_bcb_PF, shunt_SR_acb_PF, cable_PF, line_a_load_PF, line_b_load_PF, line_3_PF, dummy_load_bus_psha_PF});

	// small power flow
	auto systemPF = SystemTopology(50, // das ist freq??
			SystemNodeList{BUS_gas_PF, BUS_b_PF, BUS_a_PF, BUS_shunt_a_PF, BUS_shunt_b_PF, BUS_psha_PF},
			SystemComponentList{GEN_gas_PF, TR_gas_PF, shunt_SR_bcb_PF, shunt_SR_acb_PF, cable_PF, line_a_load_PF, line_b_load_PF, dummy_load_bus_psha_PF, line_3_PF});

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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// ----- Dynamic simulation ------
	String simNameEMT = simName + "_DP";
	Logger::setLogDir("logs/"+simNameEMT);

	// Nodes
	auto BUS_gas_DP = SimNode<Complex>::make("BUS_gas", PhaseType::Single);
	auto BUS_a_DP = SimNode<Complex>::make("BUS_a", PhaseType::Single);
	auto BUS_b_DP = SimNode<Complex>::make("BUS_b", PhaseType::Single);
	auto BUS_shunt_b_DP = SimNode<Complex>::make("BUS_shunt_b", PhaseType::Single);
	auto BUS_shunt_a_DP = SimNode<Complex>::make("BUS_shunt_a", PhaseType::Single);
	auto BUS_psha_DP = SimNode<Complex>::make("BUS_psha", PhaseType::Single);
	


	// Components

	//Synchronous generator 1
	// simple generator model
	//auto GEN_gas_EMT = EMT::Ph3::SynchronGeneratorTrStab::make("GEN_gas", Logger::Level::debug);
	// Xpd is given in p.u of generator base at transfomer primary side and should be transformed to network side
	//GEN_gas_EMT->setStandardParametersPU(generic_model_B_A.nomPower_G1, generic_model_B_A.nomPhPhVoltRMS_G1, generic_model_B_A.nomFreq_G1, 
	//			 generic_model_B_A.Xpd_G1*std::pow(generic_model_B_A.t1_ratio,2), cmdInertia_G1*generic_model_B_A.H_G1, generic_model_B_A.Rs_G1, cmdDamping_G1*generic_model_B_A.D_G1);
	// Get actual active and reactive power of generator's Terminal from Powerflow solution
	//Complex initApparentPower_G1= GEN_gas_PF->getApparentPower();
	
	//GEN_gas_EMT->setInitialValues(initApparentPower_G1, generic_model_B_A.initMechPower_G1);
	
	/*
	auto GEN_gas_EMT =
      CPS::EMT::Ph3::SynchronGeneratorVBR::make("GEN_gas", Logger::Level::debug);
  GEN_gas_EMT->setBaseAndOperationalPerUnitParameters(
      syngenKundur.nomPower, syngenKundur.nomVoltage, syngenKundur.nomFreq,
      syngenKundur.poleNum, syngenKundur.nomFieldCurr, syngenKundur.Rs,
      syngenKundur.Ld, syngenKundur.Lq, syngenKundur.Ld_t, syngenKundur.Lq_t,
      syngenKundur.Ld_s, syngenKundur.Lq_s, syngenKundur.Ll, syngenKundur.Td0_t,
      syngenKundur.Tq0_t, syngenKundur.Td0_s, syngenKundur.Tq0_s,
      syngenKundur.H);
*/
	//generator TrStab  - working myb
	auto GEN_gas_DP = DP::Ph1::SynchronGeneratorTrStab::make("GEN_gas", Logger::Level::debug);
	
	GEN_gas_DP->setStandardParametersPU(
      50e6, 10.5e3, 50,
      0.31 * std::pow(10.5e3/220e3, 2),
      5, 0.002,
      0);

 	// 	 GEN_gas_DP->setBaseAndOperationalPerUnitParameters(
    //   50e6/*nomPower*/, 10.5e3/*nomVoltage*/, 50/*nomFreq*/,
    //   2/*poleNum*/, 1300/*nomFieldCurr*/, 0.002/*Rs*/,
    //   2.4/*Ld*/, 1.33 /*Lq*/, 0.31/*Ld_t*/, 1.2/*Lq_t*/,
    //   0.24/*Ld_s*/, 0.35/*Lq_s*/, 0.135/*Ll*/, 1.45/*Td0_t*/,
    //   0.000001/*Tq0_t*/, 0.022/*Td0_s*/, 0.0095/*Tq0_s*/,
    //   5/*H*/);

	GEN_gas_DP->addGovernor(0.3, 7.0, 0.5, 0.3,
                     0.3, 0.4, 20, 0.1,
                     0.3, 0.30880873930480557e6	 / 50e6,
                     0.30880873930480557e6 / 50e6);
					//  (Real Ta, Real Tb, Real Tc, Real Fa,
                    //                       Real Fb, Real Fc, Real K, Real Tsr,
                    //                       Real Tsm, Real Tm_init, Real PmRef)

	GEN_gas_DP->addExciter(0.01 /*Real Ta*/, 500 /*Real Ka*/, 0.46 /*Real Te*/, -0.0435 /*Real Ke*/,
                         1 /*Real Tf*/, 0.1 /*Real Kf*/, 0.01 /*Real Tr*/, 7.65 /*MaxVr*/, -6.5 /*MinVr*/);

    // GEN_gas_DP->addExciter(0.06, 46, 0.46, -0.0435,
    //                 1, 0.1, 0.02); // old
	// GEN_gas_DP->addExciter(1.2, 500, 0.46, -0.0435,
    //                 1, 0.1, 0.01);
					// (Real Ta, Real Ka, Real Te, Real Ke,
                    //                      Real Tf, Real Kf, Real Tr)
	// GEN_gas_DP->setInitialValues(0.30880873930480557e6, -5.041675131002194,
    //                     10.5e3, 0,
    //                     0.30880873930480557e6);

	GEN_gas_DP->setInitialValues(Complex (0.30880873930480557e6, -5.041675131002194e6),
                                                        0.30880873930480557e6);


	// generator TRstab - end 
	
	//generator 4 order dp - begin
	// auto GEN_gas_DP = DP::Ph1::SynchronGenerator4OrderVBR::make("GEN_gas", Logger::Level::debug);
	
  	// // GEN_gas_DP->setOperationalParametersPerUnit(
    // //   50e6 /*nomPower*/, 10.5e3 /*Real nomVolt*/, 50 /*Real nomFreq*/, 5 /*Real H*/,
    // //   2.4 /*Real Ld*/,  1.33 /*Real Lq*/, 0.135 /*Ll*/, 0.31 /*Real Ld_t*/,
    // //   1.2 /*Real Lq_t*/, 1.45 /*Td0_t*/, 0.000001 /*Real Tq0_t*/,
    // //   0.24/*Real Ld_s*/, 0.35/*Real Lq_s*/, 0.022/*Real Td0_s*/,
    // //   0.0095/*Real Tq0_s*/);

	//  GEN_gas_DP->setOperationalParametersPerUnit(50e6 /*nomPower*/, 10.5e3 /*Real nomVolt*/,
    //                                    50 /*Real nomFreq*/, 5 /*Real H*/, 2.4 /*Real Ld*/, 1.33 /*Real Lq*/,
    //                                    0.1 /*Real L0*/, 0.31 /*Real Ld_t*/, 1.2 /*Real Lq_t*/,
    //                                    1.45 /*Td0_t*/, 0.000001 /*Real Tq0_t*/);

 	//  //GEN_gas_DP->setInitialValues(Complex(0.30880800989900337e6, -5.404225710964056e6), 0.30880800989900337e6, Complex (10.5e3, 0));
  	// GEN_gas_DP->setModelAsNortonSource(true);

	// GEN_gas_DP->addExciter(0.01 /*Real Ta*/, 500 /*Real Ka*/, 0.46 /*Real Te*/, -0.0435 /*Real Ke*/,
    //                      1 /*Real Tf*/, 0.1 /*Real Kf*/, 0.01 /*Real Tr*/, 7.65 /*MaxVr*/, -6.5 /*MinVr*/);
	
  // generator 4 order dp - end

	// generator 6 order b - begin
	// auto GEN_gas_DP =
    //   DP::Ph1::SynchronGenerator6bOrderVBR::make("GEN_gas", Logger::Level::debug);

	// GEN_gas_DP->setOperationalParametersPerUnit(50e6 /*nomPower*/, 10.5e3 /*Real nomVolt*/,
    //                                    50 /*Real nomFreq*/, 5 /*Real H*/, 2.4 /*Real Ld*/, 1.33 /*Real Lq*/,
    //                                    0.1 /*Real L0*/, 0.31 /*Real Ld_t*/, 1.2 /*Real Lq_t*/,
    //                                    1.45 /*Td0_t*/, 0.000001 /*Real Tq0_t*/, 0.24/*Real Ld_s*/, 
	// 								   0.35/*Real Lq_s*/, 0.022/*Real Td0_s*/, 0.0095/*Real Tq0_s*/, 0/*Real Taa = 0*/);


													   
	// GEN_gas_DP->addExciter(0.01 /*Real Ta*/, 500 /*Real Ka*/, 0.46 /*Real Te*/, -0.0435 /*Real Ke*/,
    //                      1 /*Real Tf*/, 0.1 /*Real Kf*/, 0.01 /*Real Tr*/, 7.65 /*MaxVr*/, -6.5 /*MinVr*/);   
	
	// GEN_gas_DP->addGovernor(0.2 /*Real T3*/, 0.2 /*Real T4*/, 0.2 /*Real T5*/, 0.2 /*Real Tc*/,
    //                  20 /*Real Ts*/, 0.04 /*Real R*/, 0.0 /*Real Pmin*/, 100.0 /*Real Pmax*/,
    //                  1.0 /*Real OmRef*/, 0.30880800989900337e6 / 50e6 /*Real TmRef*/);

	
	// GEN_gas_DP->setInitialValues(Complex (0.30880800989900337e6, -5.404225710964056e6),
    //                     0.30880800989900337e6, std::polar (10.5e3, 0.0));

	// generator 6 order b - end

	// voltage source
	// auto GEN_gas_DP = DP::Ph1::VoltageSource::make("GEN_gas", Logger::Level::debug);
	// GEN_gas_DP->setParameters(Complex(10.5e3, 0), 50);

	// Trafo
	auto TR_gas_DP = DP::Ph1::Transformer::make("TR_gas", "TR_gas", Logger::Level::debug, true);
	TR_gas_DP->setParameters(generic_model_B_A.nomPhPhVoltRMS_G1, generic_model_B_A.Vnom, generic_model_B_A.nomPower_G1,
                     (generic_model_B_A.nomPhPhVoltRMS_G1/generic_model_B_A.Vnom), 0, 1.82078864*2,
                     0.15518646*2);
	

	// Load
	auto load_shunt_bus_b_DP = DP::Ph1::RXLoad::make("shunt_SR_bcb", Logger::Level::debug);
	load_shunt_bus_b_DP->setParameters((1.0*220000)*(1.0*220000)/(322698.9333), 
									(1.0*220000)*(1.0*220000)/(3226.9893), generic_model_B_A.Vnom);

	auto load_shunt_bus_a_DP = DP::Ph1::RXLoad::make("shunt_SR_acb", Logger::Level::debug);
	load_shunt_bus_a_DP->setParameters((1.0*220000)*(1.0*220000)/(322698.9333), 
									(1.0*220000)*(1.0*220000)/(3226.9893), generic_model_B_A.Vnom);

	auto dummy_load_bus_psha_DP = DP::Ph1::RXLoad::make("dummy_load_bus_psha", Logger::Level::debug);
	dummy_load_bus_psha_DP->setParameters(0, 0, generic_model_B_A.Vnom);

	// Cable
	auto cable_DP = DP::Ph1::PiLine::make("cable", Logger::Level::debug);
	cable_DP->setParameters(generic_model_B_A.cableResistance, 
	                      generic_model_B_A.cableInductance, 
					      generic_model_B_A.cableCapacitance,
						  generic_model_B_A.cableConductance);

	// Line3
	auto line3_DP = DP::Ph1::PiLine::make("line_3", Logger::Level::debug);
	line3_DP->setParameters(generic_model_B_A.lineResistance3, 
	                      generic_model_B_A.lineInductance3, 
					      generic_model_B_A.lineCapacitance3,
						  generic_model_B_A.lineConductance3);



	// Switch
	auto breaker_a_DP = CPS::DP::Ph1::varResSwitch::make("breaker_a", Logger::Level::debug);
	breaker_a_DP->setParameters(SwitchOpen, SwitchClosed, true);
	breaker_a_DP->setInitParameters(timeStep);
	breaker_a_DP->close();

	auto breaker_b_DP = CPS::DP::Ph1::varResSwitch::make("breaker_b", Logger::Level::debug);
	breaker_b_DP->setParameters(SwitchOpen, SwitchClosed, true);
	breaker_b_DP->setInitParameters(timeStep);
	breaker_b_DP->close();

	
	
	

	// Topology
	//GEN_gas_DP->connect({BUS_gas_DP, DP::SimNode::GND}); 
	GEN_gas_DP->connect({BUS_gas_DP});
	TR_gas_DP->connect({BUS_gas_DP, BUS_b_DP});
	cable_DP->connect({BUS_b_DP, BUS_a_DP});
	breaker_b_DP->connect({BUS_b_DP, BUS_shunt_b_DP});
	breaker_a_DP->connect({BUS_a_DP, BUS_shunt_a_DP});
	line3_DP->connect({BUS_a_DP, BUS_psha_DP});
	load_shunt_bus_b_DP->connect({BUS_shunt_b_DP});
	load_shunt_bus_a_DP->connect({BUS_shunt_a_DP});
	dummy_load_bus_psha_DP->connect({BUS_psha_DP});
	//dummy_load_bus_b_EMT->connect({ BUS_b_EMT });
	//breaker_b_EMT->connect({BUS_b_EMT, BUS_dummy_EMT});
	//trafo_2->connect({BUS_dummy_EMT, BUS_l2_EMT});
	//load_bus_l2_EMT->connect({ BUS_l2_EMT });
	

	auto systemEMT = SystemTopology(50,
			SystemNodeList{BUS_gas_DP, BUS_b_DP, BUS_a_DP, BUS_shunt_b_DP, BUS_shunt_a_DP, BUS_psha_DP},
			SystemComponentList{GEN_gas_DP, TR_gas_DP, cable_DP, breaker_b_DP, breaker_a_DP, load_shunt_bus_b_DP, 
								load_shunt_bus_a_DP, dummy_load_bus_psha_DP, line3_DP});

	// Initialization of dynamic topology
	systemEMT.initWithPowerflow(systemPF, Domain::DP);

	for (auto attr : BUS_gas_DP->attributes()) {
    	std::string name = attr.first;
    	std::cout << name << std::endl;
  	}


	// Logging
	auto loggerEMT = DataLogger::make(simNameEMT);
	loggerEMT->logAttribute("BUS_gas_DP_v", BUS_gas_DP->attribute("v"));
	loggerEMT->logAttribute("BUS_b_DP_v", BUS_b_DP->attribute("v"));
	//loggerEMT->logAttribute("GEN_gas_EMT_ep_mag", GEN_gas_EMT->attribute("Ep_mag"));
	// loggerEMT->logAttribute("GEN_gas_EMT_v", GEN_gas_EMT->attribute("v_intf"));
	// loggerEMT->logAttribute("GEN_gas_EMT_i", GEN_gas_EMT->attribute("i_intf"));
	// loggerEMT->logAttribute("GEN_gas_EMT_wr", GEN_gas_EMT->attribute("w_r"));
	// loggerEMT->logAttribute("GEN_gas_EMT_delta", GEN_gas_EMT->attribute("delta_r"));	
	//loggerEMT->logAttribute("P_mech1", GEN_gas_EMT->attribute("P_mech"));
	//loggerEMT->logAttribute("P_elec1", GEN_gas_EMT->attribute("P_elec"));
	

	Simulation simEMT(simNameEMT, Logger::Level::debug);
  	simEMT.doInitFromNodesAndTerminals(true);
  	simEMT.setSystem(systemEMT);
  	simEMT.setTimeStep(timeStep);
  	simEMT.setFinalTime(finalTime);
  	simEMT.setDomain(Domain::DP);
  	simEMT.addLogger(loggerEMT);
	simEMT.doSystemMatrixRecomputation(true);

	if (useVarResSwitch == true) {
		simEMT.doSystemMatrixRecomputation(true);
	}

	if (startFaultEvent){
		auto sw1 = SwitchEvent::make(startTimeFault, breaker_b_DP, false);
		auto sw2 = SwitchEvent::make(startTimeFault, breaker_a_DP, false);
		simEMT.addEvent(sw1);
		simEMT.addEvent(sw2);
	}


	simEMT.run();

}

int main(int argc, char* argv[]) {	
		
/*
	//Simultion parameters
	String simName="scenario_B_step_A";
	Real finalTime = 30;
	Real timeStep = 0.001;
	
	scenario_B_step_A(simName, timeStep, finalTime);
*/

//Simultion parameters
	String simName="scenario_F_step_A";
	Real finalTime = 60.0;
	Real timeStep = 0.001;
	Bool startFaultEvent=true;
	Bool endFaultEvent=true;
	Bool useVarResSwitch=false;
	Real startTimeFault=10;
	Real endTimeFault=11100;
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
	
	scenario_F_step_A_EMT(simName, timeStep, finalTime, startFaultEvent, endFaultEvent, startTimeFault, endTimeFault, useVarResSwitch, cmdInertia_G1, cmdDamping_G1);

}