BacktrackingProcedure( someVector, dimension)
{
  if(someVector==isSolution)
    PrintSolution OR StoreSolution
  else
    CheckAllPromisingCandidates(i)
    {
      someVector addPromissingCandidate(i);
      checkIfCandidatePromising(i);
      BacktrackingProcedure(temporatyVector, increaseDimenzsionOfVector);
    }
}

char solver(grid[4][4], x, y)
{
    //si num dasn grid[i1][i2] respecte la regle -> stock
        // i1 ++ et on recommence
    //sinon
        //on fait num ++ jusqua 4, 
            //si ok on stock
            //si toujours rien on i1 --
                //on reprends i et on ++

}