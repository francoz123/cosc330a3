void
Get_data4 (int me, double *a_ptr, double *b_ptr, double *c_ptr, int *ai_ptr,
	   int *bi_ptr, int *ci_ptr,)
{
  int root = 0, position = 0;
  char buffer[100];
  if (me == 0)
    {
      printf ("Enter a, b, and n\n");
      scanf ("%f %f %d", a_ptr, b_ptr, n_ptr);
      MPI_Pack (a_ptr, 1, MPI_DOUBLE, buffer, 100, &position, MPI_COMM_WORLD);
      MPI_Pack (b_ptr, 1, MPI_DOUBLE, buffer, 100, &position, MPI_COMM_WORLD);
      MPI_Pack (c_ptr, 1, MPI_DOUBLE, buffer, 100, &position, MPI_COMM_WORLD);
      MPI_Pack (ai_ptr, 1, MPI_INT, buffer, 100, &position, MPI_COMM_WORLD);
      MPI_Pack (bi_ptr, 1, MPI_INT, buffer, 100, &position, MPI_COMM_WORLD);
      MPI_Pack (ci_ptr, 1, MPI_INT, buffer, 100, &position, MPI_COMM_WORLD);

      MPI_Bcast (buffer, 100, MPI_PACKED, root, MPI_COMM_WORLD);
    }
  else
    {
      MPI_Bcast (buffer, 100, MPI_PACKED, root, MPI_COMM_WORLD);
      MPI_Unpack (buffer, 100, &position, a_ptr, 1, MPI_DOUBLE,
		  MPI_COMM_WORLD);
      MPI_Unpack (buffer, 100, &position, b_ptr, 1, MPI_DOUBLE,
		  MPI_COMM_WORLD);
      MPI_Unpack (buffer, 100, &position, c_ptr, 1, MPI_DOUBLE,
		  MPI_COMM_WORLD);
      MPI_Unpack (buffer, 100, &position, ai_ptr, 1, MPI_INT, MPI_COMM_WORLD);
      MPI_Unpack (buffer, 100, &position, bi_ptr, 1, MPI_INT, MPI_COMM_WORLD);
      MPI_Unpack (buffer, 100, &position, ci_ptr, 1, MPI_INT, MPI_COMM_WORLD);
    }
}
