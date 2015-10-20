int maximal(graphe g, int e[])
{
    int x=0;
    int ok=1;
    if(verification(g,e))
    {
        do
        {
            if(!e[x])
            {
                e[x]=1;
                ok=!verification(g,e);
                e[x]=0;
            }
            x=x+1;
        }while((x<g.n) && ok);
    }
    else
        ok=0;
    return ok;
} 

