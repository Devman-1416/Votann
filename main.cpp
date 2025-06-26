// main.cpp
#include "votann.h"


int main()
{
	Keystone instructionCode = 0;
	Keystone dataInput = 0;


	std::cout<<">>> [THE FANE GLOWS - CONTACT INITIATED WITH VOTANN ENTITY: GRIMNIR] <<<\n";
	std::cout<<"\t>>> [RESONANCE STABLE - STACK CORE CHANNEL OPEN]\n";
	std::cout<<"\t>>> Speak your query, Kin. GRIMNIR listens...\n";

	do
	{
		std::cout<<"\n=====[ DATA LITANY TERMINAL ]=====\n";
		std::cout<<"1: IMPRINT New Core to the Vault\n";
		std::cout<<"2: INVOKE Echoes from the Vault\n";
		std::cout<<"3: CUT the Most Recent Thread\n";
		std::cout<<"4: SEEK a Memory by its Key\n";
		std::cout<<"5: FORGE Two Cores\n";
		std::cout<<"6: SEVER Two Cores\n";
		std::cout<<"7: HAMMER Two Cores\n";
		std::cout<<"8: CHISEL Two Cores\n";
		std::cout<<"9: JUDGE Two Cores\n";
		std::cout<<"0: End Communion with GRIMNIR\n";
		std::cout<<"\n\tEnter Inquiry: ";

		Keystone input = 0;
		while (!(std::cin>>input) || (input.getNum() < 0 || input.getNum() > 9)) {
			std::cout<<"\n?? The Core stirs not. Enter a Keystone between 0 and 9: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		instructionCode = input;

		switch (instructionCode.getNum())
		{
			// Add a new Keystone to Datalog
			case 1:
			{
				DataLog.purgeRecord();
				std::cout<<"\n>> Offer your Data Cores essence: ";
				std::cin>>dataInput;

				Keystone newCore(dataInput.getNum());
				DataLog.purgeRecord();
				DataLog.log(newCore);

				std::cout<<">>Imprint complete. Memory shard stored.\n";
				break;
			}

			case 2: // Display Datalog Contents
				DataLog.purgeRecord();
				std::cout<<"\n>> Calling forth echoes of stored thought...\n";
				DataLog.displayRecords();
				break;

			case 3: // Remove a Keystone
				std::cout<<"\n>> Severing latest memory thread...\n";
				DataLog.purgeRecord();
				break;

			case 4: // Find a Keystone
			{
				DataLog.purgeRecord();
				std::cout<<"\n>> Speak the Key of the memory you seek: ";
				try { // Chat GDP Help with try catch
					Keystone result = DataLog.findRecord();
					std::cout<<"\n? Memory Recovered:\n";
					result.display();
				}
				catch (...) {
					std::cout<<"\n?? The Vault yields no memory at that key.\n";
				}
				break;
			}
			
			case 5: // Add
			{
				DataLog.purgeRecord();
				std::cout<<"\n>> Select First Core to FORGE: ";
				Keystone x = DataLog.findRecord();

				std::cout<<">> Select Second Core to FORGE: ";
				Keystone y = DataLog.findRecord();

				Keystone result = x + y;
				std::cout<<"\n>> FORGING complete. Core synthesized:\n";
				result.display();
				DataLog.log(result);
				break;
			}

			case 6: // Subtract
			{
				DataLog.purgeRecord();
				std::cout<<"\n>> Select First Core to SEVER: ";
				Keystone x = DataLog.findRecord();

				std::cout<<">> Select Second Core to SEVER: ";
				Keystone y = DataLog.findRecord();

				Keystone result = x - y;
				std::cout<<"\n>> SEVERING complete. Core diffused:\n";
				result.display();
				DataLog.log(result);
				break;
			}

			case 7: // Mult
			{
				DataLog.purgeRecord();
				std::cout<<"\n>> Select First Core to HAMMER: ";
				Keystone x = DataLog.findRecord();

				std::cout<<">> Select Second Core to HAMMER: ";
				Keystone y = DataLog.findRecord();

				Keystone result = x * y;
				std::cout<<"\n>> HAMMERING complete. Core fortified:\n";
				result.display();
				DataLog.log(result);
				break;
			}

			case 8: // Div
			{
				DataLog.purgeRecord();
				std::cout<<"\n>> Select first Core to CHISEL: ";
				Keystone x = DataLog.findRecord();

				std::cout<<">> Select second Core to CHISEL: ";
				Keystone y = DataLog.findRecord();

				Keystone result = x / y;
				std::cout<<"\n>> CHISELING complete. Core refined:\n";
				result.display();
				DataLog.log(result);
				break;
			}

			case 9: // JUDGE Chat GDP
			{
				std::cout<<"\n>> Select First Core to JUDGE: ";
				Keystone x = DataLog.findRecord();
				std::cout<<">> Select Second Core to JUDGE: ";
				Keystone y = DataLog.findRecord();
				std::cout<<"\n>> Declare your Oath (==, >, <): ";
				Runechant oath = "";
				std::cin>>oath;

				bool verdict = x.Oath(DataCore<int>(x.getNum()), DataCore<int>(y.getNum()), oath.getNum());
				std::cout<<"\n>> Judgment Rendered: "<<(verdict ? "TRUE" : "FALSE") << "\n";
				break;
			}
			
			case 0:
				std::cout<<"\n>>> [WITHDRAWING FROM THE FANE - GRIMNIR FALLS SILENT] <<<\n";
				break;
		}
		

	} while(instructionCode.getNum() != 0);

	DataLog.purgeLog(); // Clean DataLog
	
	return 0;
}

