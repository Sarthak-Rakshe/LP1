//First Come First Serve (FCFS)
#include<iostream>
using namespace std;
int main()
{
	int    at[20]       ,       bt[20]    ,      ct[20]          ,       tat[20]         ,   wt[20] ,g[20];;
	//at arrival time	bt=burst time	ct =completion time 	tat= turnaround time  wt=waiting time
	int p,j=1;
	float avgt = 0, avgw = 0;
	cout<<"Enter the number of process ";
	cin>>p;
	cout<<"Enter the arrival time for "<<p<<" processes -  \n";
	for(int i=0;i<p;i++)
	{
		cin>>at[i];
	}
	cout<<"Enter the burst time for "<<p<<" processes -  \n";
	for(int i=0;i<p;i++)
	{
		cin>>bt[i];
	}
	// cout<<"Enter the completion time for "<<p<<" processes -  \n";
	// for(int i=0;i<p;i++)
	// {
	// 	cin>>ct[i];
	// }
	cout<<"Completion Time is: "<<endl;
		ct[0] = bt[0];
		for (int i = 1; i < p; i++) {
			ct[i] = ct[i - 1] + bt[i];
			cout<<ct[i];
			cout<<"\n";
		}

	cout<<"Turn Around time is - \n";
	for(int i=0;i<p;i++)
	{
	
		tat[i]=ct[i]-at[i];
		cout<<tat[i];
		cout<<"\n";
	}
	cout<<"Waiting time is - \n";
	for(int i=0;i<p;i++)
	{
	
		wt[i]=tat[i]-bt[i];
		cout<<wt[i];
		cout<<"\n";
	}
	cout<<"Tabular format for FCFS is - \n";
     cout<<"| Process Number |    |  Arrival Time  |    |  Burst time  |    |  Turnaround time  |    |  Waiting time | ";     
	for(int i=0;i<p;i++)
	{
		cout<<"\n       P"<<j++<<"\t\t\t"<<at[i]<<"\t\t    "<<bt[i]<<"\t\t       "<<tat[i]<<"\t\t\t    "<<wt[i];
		cout<<"\n";
	}
	cout<<"________________________________________________________________________________________________________";
	cout<<"\n\n";
	cout<<"Average of turnaround time is : ";
	for(int i=0;i<p;i++)
	{
		avgt = avgt + tat[i];
	}
	cout<<avgt/p;
	cout<<"\n";
	cout<<"Average of waiting time is : ";
	for(int i=0;i<p;i++)
	{
		avgw = avgw + wt[i];
	}
	cout<<avgw/p<<"\n";
	cout<<"\n\n";
}

//ip
//4
//0 1 5 6
//2 2 3 4
//2  4 8 12