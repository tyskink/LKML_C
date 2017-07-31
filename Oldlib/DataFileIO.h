#pragma once

namespace lk_MachineLearning
{
	class DataFileIO
	{
	public:
		DataFileIO();
		~DataFileIO();

		// read Matrix from a .kldouble file
		int readMatrix(const char*fileaddress, double*Matrix);

		//display a matrix of double format
		int displayMatrix(double *A, int A_row, int A_colum);


	};

}
