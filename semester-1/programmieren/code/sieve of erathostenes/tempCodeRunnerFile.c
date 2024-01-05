 main(void)
{
  double mw1, mw2;
  mw1 = nimmzeit();
  printf("\n... druecke beliebige Taste\n");
  getch();
  mw2 = nimmzeit();
  printf("\nvergangene Zeit: %.3f sec\n",mw2-mw1);

  return 0;
}
