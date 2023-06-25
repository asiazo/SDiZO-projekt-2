//
// Created by Joanna on 02.06.2023.
//

#include "AutomaticTest.h"
#include <fstream>
#include <iostream>
#include "../Graph/GraphMatrix.h"
#include "Time.h"
#include "../Algorithms/Prim.h"
#include "../Algorithms/Kruskal.h"
#include "../Algorithms/Dijkstra.h"
#include "../Algorithms/BellmanFord.h"

using namespace std;
void AutomaticTest::testMst()
{
    int count = 1000, d;
    long double avg=0;
    Time time;
    ofstream output;
    output.open("resultsU.txt");
    for(d=25; d<=75; d=d+25)
    {
        cout<<"d="<<d<<endl;
        output<<d<<endl;
        output<<" Prim Matrix"<<endl;
        for(int n=10; n<=100; n=n+10) //Prim Matrix
        {
            cout<<"Prim Matrix n="<<n<<endl;
            for(int i=0; i<count; i++)
            {
                Prim prim;
                GraphMatrix graphMatrix(n);
                graphMatrix.generateUndirectedRandomGraph(n,d);
                time.start();
                prim.forMatrixAuto(graphMatrix);
                time.stop();
                avg = avg + time.returnTime();
            }
            avg = avg/count;
            output<<avg<<" ";
        }
        output<<endl;
        output<<" Prim List"<<endl;
        for(int n=10; n<=100; n=n+10) //Prim List
        {
            cout<<"Prim List n="<<n<<endl;
            for(int i=0; i<count; i++)
            {
                Prim prim;
                GraphList graphList(n);
                graphList.randomGraphUndirected(n,d);
                time.start();
                prim.forListAuto(graphList);
                time.stop();
                avg = avg + time.returnTime();
            }
            avg = avg/count;
            output<<avg<<" ";
        }
        output<<endl;
        output<<" Kruskal Matrix"<<endl;
        for(int n=10; n<=100; n=n+10) //Kruskal Matrix
        {
            cout<<"Kruskal Matrix n="<<n<<endl;
            for(int i=0; i<count; i++)
            {
                Kruskal kruskal;
                GraphMatrix graph(n);
                graph.generateUndirectedRandomGraph(n,d);
                time.start();
                kruskal.forMatrixAuto(graph);
                time.stop();
                avg = avg + time.returnTime();
            }
            avg = avg/count;
            output<<avg<<" ";
        }
        output<<endl;
        output<<" Kruskal List"<<endl;
        for(int n=10; n<=100; n=n+10) //Kruskal List
        {
            cout<<"Kruskal List n="<<n<<endl;
            for(int i=0; i<count; i++)
            {
                Kruskal kruskal;
                GraphList graphList(n);
                graphList.randomGraphUndirected(n,d);
                time.start();
                kruskal.forListAuto(graphList);
                time.stop();
                avg = avg + time.returnTime();
            }
            avg = avg/count;
            output<<avg<<" ";
        }
        output<<endl;
    }
    d=99;
    {
        cout<<"d="<<d<<endl;
        output<<d<<endl;
        output<<" Prim Matrix"<<endl;
        for(int n=10; n<=100; n=n+10) //Prim Matrix
        {
            cout<<"Prim Matrix n="<<n<<endl;
            for(int i=0; i<count; i++)
            {
                Prim prim;
                GraphMatrix graphMatrix(n);
                graphMatrix.generateUndirectedRandomGraph(n,d);
                time.start();
                prim.forMatrixAuto(graphMatrix);
                time.stop();
                avg = avg + time.returnTime();
            }
            avg = avg/count;
            output<<avg<<" ";
        }
        output<<endl;
        output<<" Prim List"<<endl;
        for(int n=10; n<=100; n=n+10) //Prim List
        {
            cout<<"Prim List n="<<n<<endl;
            for(int i=0; i<count; i++)
            {
                Prim prim;
                GraphList graphList(n);
                graphList.randomGraphUndirected(n,d);
                time.start();
                prim.forListAuto(graphList);
                time.stop();
                avg = avg + time.returnTime();
            }
            avg = avg/count;
            output<<avg<<" ";
        }
        output<<endl;
        output<<" Kruskal Matrix"<<endl;
        for(int n=10; n<=100; n=n+10) //Kruskal Matrix
        {
            cout<<"Kruskal Matrix n="<<n<<endl;
            for(int i=0; i<count; i++)
            {
                Kruskal kruskal;
                GraphMatrix graph(n);
                graph.generateUndirectedRandomGraph(n,d);
                time.start();
                kruskal.forMatrixAuto(graph);
                time.stop();
                avg = avg + time.returnTime();
            }
            avg = avg/count;
            output<<avg<<" ";
        }
        output<<endl;
        output<<" Kruskal List"<<endl;
        for(int n=10; n<=100; n=n+10) //Kruskal List
        {
            cout<<"Kruskal List n="<<n<<endl;
            for(int i=0; i<count; i++)
            {
                Kruskal kruskal;
                GraphList graphList(n);
                graphList.randomGraphUndirected(n,d);
                time.start();
                kruskal.forListAuto(graphList);
                time.stop();
                avg = avg + time.returnTime();
            }
            avg = avg/count;
            output<<avg<<" ";
        }
        output<<endl;
    }
    output.close();
}
void AutomaticTest::testP()
{
    int count = 1000   , d;
    long double avg=0;
    Time time;
    ofstream output;
    output.open("resultsD.txt");
    for(d=25; d<=75; d=d+25)
    {
        cout<<"d="<<d<<endl;
        output<<d<<endl;
        output<<" Dijkstra Matrix"<<endl;
        for(int n=10; n<=100; n=n+10) //Dijkstra Matrix
        {
            cout<<"Dijkstra Matrix n="<<n<<endl;
            for(int i=0; i<count; i++)
            {
                Dijkstra dijkstra;
                GraphMatrix graphMatrix(n);
                graphMatrix.generateDirectedRandomGraph(n,d);
                time.start();
                dijkstra.forMatrixAuto(graphMatrix,0);
                time.stop();
                avg = avg + time.returnTime();
            }
            avg = avg/count;
            output<<avg<<" ";
        }
        output<<endl;
        output<<"Dijkstra List"<<endl;
        for(int n=10; n<=100; n=n+10)
        {
            cout<<"Dijkstra List n="<<n<<endl;
            for(int i=0; i<count; i++)
            {
                Dijkstra dijkstra;
                GraphList graphList(n);
                graphList.randomGraphDirected(n,d);
                time.start();
                dijkstra.forListAuto(graphList,0);
                time.stop();
                avg = avg + time.returnTime();
            }
            avg = avg/count;
            output<<avg<<" ";
        }
        output<<endl;
        output<<"Bellman-Ford Matrix"<<endl;
        for(int n=10; n<=100; n=n+10)
        {
            cout<<"Bellman-Ford Matrix n="<<n<<endl;
            for(int i=0; i<count; i++)
            {
                BellmanFord bellmanFord;
                GraphMatrix graph(n);
                graph.generateDirectedRandomGraph(n,d);
                time.start();
                bellmanFord.forMatrixAuto(graph,0, true);
                time.stop();
                avg = avg + time.returnTime();
            }
            avg = avg/count;
            output<<avg<<" ";
        }
        output<<endl;
        output<<"Bellman-Ford List"<<endl;
        for(int n=10; n<=100; n=n+10) //Kruskal List
        {
            cout<<"Bellman-Ford List n="<<n<<endl;
            for(int i=0; i<count; i++)
            {
                BellmanFord bellmanFord;
                GraphList graphList(n);
                graphList.randomGraphDirected(n,d);
                time.start();
                bellmanFord.forListAuto(graphList, 0, true);
                time.stop();
                avg = avg + time.returnTime();
            }
            avg = avg/count;
            output<<avg<<" ";
        }
        output<<endl;
    }
    d=99;
    {
        cout<<"d="<<d<<endl;
        output<<d<<endl;
        output<<" Dijkstra Matrix"<<endl;
        for(int n=10; n<=100; n=n+10) //Dijkstra Matrix
        {
            cout<<"Dijkstra Matrix n="<<n<<endl;
            for(int i=0; i<count; i++)
            {
                Dijkstra dijkstra;
                GraphMatrix graphMatrix(n);
                graphMatrix.generateDirectedRandomGraph(n,d);
                time.start();
                dijkstra.forMatrixAuto(graphMatrix,0);
                time.stop();
                avg = avg + time.returnTime();
            }
            avg = avg/count;
            output<<avg<<" ";
        }
        output<<endl;
        output<<"Dijkstra List"<<endl;
        for(int n=10; n<=100; n=n+10) //Prim List
        {
            cout<<"Dijkstra List n="<<n<<endl;
            for(int i=0; i<count; i++)
            {
                Dijkstra dijkstra;
                GraphList graphList(n);
                graphList.randomGraphDirected(n,d);
                time.start();
                dijkstra.forListAuto(graphList,0);
                time.stop();
                avg = avg + time.returnTime();
            }
            avg = avg/count;
            output<<avg<<" ";
        }
        output<<endl;
        output<<"Bellman-Ford Matrix"<<endl;
        for(int n=10; n<=100; n=n+10) //Kruskal Matrix
        {
            cout<<"Bellman-Ford Matrix n="<<n<<endl;
            for(int i=0; i<count; i++)
            {
                BellmanFord bellmanFord;
                GraphMatrix graph(n);
                graph.generateDirectedRandomGraph(n,d);
                time.start();
                bellmanFord.forMatrixAuto(graph,0, true);
                time.stop();
                avg = avg + time.returnTime();
            }
            avg = avg/count;
            output<<avg<<" ";
        }
        output<<endl;
        output<<"Bellman-Ford List"<<endl;
        for(int n=10; n<=100; n=n+10) //
        {
            cout<<"Bellman-Ford List n="<<n<<endl;
            for(int i=0; i<count; i++)
            {
                BellmanFord bellmanFord;
                GraphList graphList(n);
                graphList.randomGraphDirected(n,d);
                time.start();
                bellmanFord.forListAuto(graphList,0,true);
                time.stop();
                avg = avg + time.returnTime();
            }
            avg = avg/count;
            output<<avg<<" ";
        }
        output<<endl;
    }
    output.close();
}