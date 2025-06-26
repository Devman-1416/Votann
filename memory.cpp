class DirectiveCache // Stack Memory
{
	private:
		std::stack<DataCore> CoreBank;
		
	public:
		DirectiveCache () {;}
		
		void ForgeCore (DataCore newCore) //Add to stack
		{
			CoreBank.push(newCore);
		}
		
		void SmeltCore () //Remove from stack
		{
			CoreBank.pop();
		}
		
		DataCore TransferCore ()
		{
			return CoreBank.top();
		}
	
}; // End Directive Cache

class DataCore // The actual Data, Numbers
{
	public:
		int data;

	DataCore (int data): data(data) {;}
	
	void storeData (int data) {this->data = data;}
	int getData () {return data;}
	
}; // End Datacore
