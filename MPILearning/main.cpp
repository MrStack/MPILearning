#include"mpi.h"
#include<iostream>
#include<string>

class MPI
{
private:
public:
	MPI(int& argc, char* argv[])
	{
		MPI_Init(&argc, &argv);
	}
	~MPI(void)
	{
		MPI_Finalize();
	}

	int getProcessID(unsigned int where = MPI_COMM_WORLD) const
	{
		int rank{};
		MPI_Comm_rank(where, &rank);

		return rank;
	}
	int getCommunicatorSize(unsigned int where = MPI_COMM_WORLD) const
	{
		int numProcess{};
		MPI_Comm_size(where, &numProcess);

		return numProcess;
	}
	std::string getProcessorName(void) const
	{
		std::string processorName(MPI_MAX_PROCESSOR_NAME, ' ');
		int length{};
		MPI_Get_processor_name((char*)processorName.c_str(), &length);

		return processorName;
	}
};

int main(int argc, char* argv[])
{
	MPI MPIInterface{ argc,argv };

	std::cout << "Hello world from:" << MPIInterface.getProcessID() << " of "
		<< MPIInterface.getCommunicatorSize() << " on "
		<< MPIInterface.getProcessorName() << std::endl;	

	return 0;
}