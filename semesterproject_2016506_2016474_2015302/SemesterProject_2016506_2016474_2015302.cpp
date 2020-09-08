#include<iostream>
#include<fstream>

#include<string>
#include <vector>
	using namespace std;
	int count=1;
	int lines=0;
	 vector<int> foundindices;
		struct citi
		{
			string city;
		};
		class list
		{
			struct node
			{
				string a1,a2;
				float w;
				node *next;
			};
			node *head;
			node *front;
			
			public:
			
			list()
			{
				head = NULL;
			}
		//function to add node at tail
			void add(string n1,string n2,float wait)
			{
				node *ptrNew=new node();
				node *ptrTemp = head;
				ptrNew->a1 = n1;
				ptrNew->a2 = n2;
				ptrNew->w = wait;
				ptrNew->next = NULL;
				if(head == NULL)
				{
					head = ptrNew;
					return;
				}
				while(ptrTemp->next != NULL)
				{
					ptrTemp = ptrTemp->next;
				}
				ptrTemp->next = ptrNew;
			}
			//display function
			void display()
			{
				node *temp=head;
				while(temp!=NULL)
				{
					cout<<temp->a1<<"\t"<<temp->a2<<"\t"<<temp->w<<endl;
					temp=temp->next;
				}
			}
		
		void nodes()
		{
			node *temp=head;
			while(temp->next!=NULL)
			{
				if(temp->a1!=temp->next->a1)
				count++;
				temp=temp->next;
			}
		}
		void del()
		{
			node *temp=head;
			head=head->next;
			delete temp;
		}
		list graph()
		{
			node *temp=head;
			list l2;
			while (temp->next!=NULL)
			{
				if(temp->a1==temp->next->a1)
				{
					del();
				}
				else
				{
					l2.add(temp->a1,temp->a2,temp->w);
				}
				temp=temp->next;
			}
				
			l2.add(temp->a1,temp->a2,temp->w);
			return l2;	
		}
		//returning first column of data
		string arrays()
		{
			node *temp=head;
			head=head->next;
			delete temp;
			return temp->a1;
		}
		
		string array2()
		{
			node *temp=head;
			head=head->next;
			delete temp;
			return temp->a2;
		}
		
		float weight()
		{
			node *temp=head;
			head=head->next;
			delete temp;
			return temp->w;
		}
		list value()
		{
			node *temp=head;
			list l2;
			while (temp->next!=NULL)
			{
				l2.add(temp->a1,temp->a2,temp->w);
				temp=temp->next;	
			}
			l2.add(temp->a1,temp->a2,temp->w);
			return l2;	
		}	
			
		};


		void location(string arr[], string array[])
		{
			string start,move;
			for (int i=0;i<lines;i++)
			{
				start=arr[i];
				cout<<start<<" : ";
				for (int j=0;j<lines;j++)
				{
						move=arr[j];
						if(start==move)
						{
							cout<<array[j]<<" ";
						}
						
				}
				cout<<endl;
			}
		}

		int find(string arr[],string seek)
		{
	    for (int i = 0; i < lines; ++i)
	    {
	        if (arr[i] == seek) return i;
	    }
	    return -1;
		}

		int density(int a,int e)
		{
			int nodes;
			float density;
			int clusteredges;
			int clusternodes;
			float periphery;
				
			cout<<"The number of edges are"<<endl;
			cout<<e;
			cout<<endl;
			cout<<"the no of nodes are"<<endl;
			cout<<a;
			cout<<endl;
			cout<<"Density of a graph"<<endl;
			density=2*e;
			density=density/(a*(a-1));	
			cout<<density;	
			cout<<endl;			
			return density;		
		}
		int largest(int arr[])
		{
		    int i;
		    int max = arr[0];
		    for (i = 1; i < count; i++)
		    
			    if (arr[i] > max)
		        max = arr[i];	
		    return max;
		}
		int largest(int arr[],int arraysize)
		{
		    int i;
		    int max = arr[0];
		    for (i = 1; i < arraysize; i++)
		    
			    if (arr[i] > max)
		        max = arr[i];	
		    return max;
		}
		
		int findindex(int arr[],int seek)
		{
	    for (int i=0;i<count; ++i)
	    {
	        if (arr[i] == seek) 
			return i;
	 	}
	    return -1;
		}
		
		void searchList(int theArray[], int findFor){
		 
		
		  int j = 0;
		
		  for (int i = 0; i < count; i++)
		  {
		    if (theArray[i] == findFor){
		      foundindices.push_back(i);
		      j++;
		    }
		  }
		
		  if (foundindices.size()!=0){
		  }
		  else
		    cout << "Not found in array";
		}

		bool densityfunction(int a,int e,float thersh)
		{
			int nodes;
			float density;
			int clusteredges;
			int clusternodes;
			float periphery;
				
			
			density=2*e;
			density=density/(a*(a-1));	
			
			if(thersh<=density)
			return true;	
			else
			return false;
			
			
		}
		
		float densityfunction1(int a,int e)
		{
			float density2;
			int clusteredges;
			int clusternodes;
			float periphery;
			cout<<endl;
			cout<<endl;
			density2=2*e;
			density2=density2/(a*(a-1));
			return density2;	
		}
		
		
		bool peripheryfunction(int no,int e,float thersh)
		{
			float beckham;	
			int clusteredges=e;
		
			int clusternodes=no;

			
			beckham=densityfunction1(clusternodes,clusteredges);
		
			float periphery;
				
			periphery=clusteredges;
			periphery=periphery/(beckham*clusternodes);

			if(periphery<=thersh)
				return true;		
			else 
				return false;
		}


		int main()
		{
			ifstream ali("fraser1.txt");
			string node1;
			string node2;
			int edges=0;
			float weight;
			list l,l1,l2,l3;
			list l4;
			
			float tdensity;
			float tperiphery;
			cout<<"Enter threshold value for density: "; cin>>tdensity;
			while(tdensity>=1)
			{
				cout<<"Invalid density! Please enter a valid density (from 0 to 1): ";
				cin>>tdensity;
			}
			cout<<"Enter threshold value for periphery: "<<endl; cin>>tperiphery;
			cout<<endl;
			
			while(ali>>node1>>node2>>weight)
			{
				l.add(node1,node2,weight);
				l1.add(node1,node2,weight);
				l2.add(node1,node2,weight);
				l3.add(node1,node2,weight);
				lines++;
			}
			
			l2=l2.value();
			l3=l3.value();
			l.nodes();
			int a=count;
			string firstrow[lines];
			string secondrow[lines];
			float w[lines];
			string arr[a];
			l1=l1.graph();
			
			//unique elements of an array
			for(int i=0;i<a;i++)
			{
				arr[i]=l1.arrays();
			}
			
			for (int i=0;i<lines;i++)
			{
				firstrow[i]=l2.arrays();
				secondrow[i]=l3.array2();
			//	cout<<firstrow[i]<<"\t"<<secondrow[i]<<endl;
			}
			
			int adjacency[a][a];
			for (int i=0;i<a;i++)
			{
				for(int j=0;j<a;j++)
				{
					adjacency[i][j]=0;
				}
			
			}
			for(int e=0;e<lines;e++ )
			{
				int x=find(arr,firstrow[e]);
				int y=find(arr,secondrow[e]);
				for (int i=0;i<a;i++)
				{
					for(int j=0;j<a;j++)
					{
						adjacency[x][y]=1;
					}
				}
			}
			for(int i=0;i<a;i++)
			{
				cout<<arr[i]<<"\t";
			}
			cout<<endl;
			
			for (int i=0;i<a;i++)
			{
				
				for(int j=0;j<a;j++)
				{
					cout<<adjacency[i][j]<<"\t";
				}
				cout<<endl;
			}
			int mata[a][a];		
		    int kaka,villa;
		    int sum,k;
					
			for(kaka=0; kaka<a; kaka++)
			{
				for(villa=0; villa<a; villa++)
				{
					sum=0;
					for(k=0; k<a; k++)
					{
						sum = sum + adjacency[kaka][k] * adjacency[k][villa];
					}
					mata[kaka][villa] = sum;
				}
			}	
			cout<<endl;
			cout<<"After M^2 :This is the weight of an edge "<<endl;
			
			for(int i=0;i<a;i++)
			{
				mata[i][i]=0;
			}
			
				for(int i=0;i<a;i++)
			{
				for(int j=0;j<a;j++)
				{
					if(mata[i][j]!=0  && adjacency[i][j]==0)
					{
						mata[i][j]=0;
					}
				}
			}
			for( kaka=0;kaka<a;kaka++)
			{
				for(villa=0;villa<a;villa++)
				{
					cout<<mata[kaka][villa]<<"\t";	
				}
				cout<<endl;
			}
			
			for (int i=0;i<a;i++)
			{
				for(int j=0;j<a;j++)
				{
					if(adjacency[i][j]==1)
					{
						edges++;
					}
				}
			}
			int gerrard=density(a,edges);
			int nodeweight[a];
			for( kaka=0;kaka<a;kaka++)
			{
				for(villa=0;villa<a;villa++)
				{
				sum=sum+mata[kaka][villa];	
				}
				nodeweight[kaka]=sum;
				cout<<"weight for node "<<arr[kaka]<<" is :"<<sum<<endl;
				
				sum=0;	
			}
			
			cout<<endl;
			int degree=0;
			cout<<"degrees : "<<endl;
			int degrees[a];
			
			for (int i=0;i<a;i++)
			{
				for(int j=0;j<a;j++)
					{
						degree+=adjacency[i][j];
					}
				degrees[i]=degree;
				cout<<"Degree for node "<<arr[i]<<" is :"<<degree<<endl;
				degree=0;
			}
			
			int highest=largest(nodeweight);
			int index=findindex(nodeweight,highest);
			string startnode=arr[index];
			
			int edgeweight[a];
			for(int j=0;j<a;j++)
			{
				edgeweight[j]=mata[index][j];
					if(edgeweight[j]==0)
				{
					continue;
				}
				cout<<arr[index]<<" with "<<j+1<<" "<<edgeweight[j]<<endl;
			
			}
			int highestedge=largest(edgeweight);
			int edgeindex=findindex(edgeweight,highestedge);
			cout<<highestedge<<"is highest edge and the edge index is"<<edgeindex<<endl;
			int clusternodes=1;
			int clusteredges=0;
			cout<<"weight = "<<highestedge<<" at "<<edgeindex<<" for node "<<arr[edgeindex];
			ofstream cluster("cluster.txt");
			cluster<<"First Cluster starts by node "<<startnode<<endl<<"Adjacent nodes are : "<<endl;
			searchList(edgeweight,highestedge);
			int maxi=0;
				
			for(int j=0;j<a;j++)
			{
				if(mata[index][edgeindex]==mata[index][j])
				{
						clusternodes++;	
						clusteredges++;
				}
					if(adjacency[index][edgeindex]==adjacency[index][edgeindex+1])
					break;
			}
			if(adjacency[foundindices[maxi]][foundindices[maxi+1]]==1)
			clusteredges++;
			for (int max = 0; max < foundindices.size(); max++)
			{
				for(int j=0;j<a;j++)
				{
					if(mata[index][edgeindex]==mata[index][j])
					{
						if((densityfunction(clusternodes,clusteredges,tdensity))&& (peripheryfunction(clusternodes,clusteredges,tperiphery)) && adjacency[index][edgeindex]==1)
						{
							cluster<<arr[foundindices[max]]<<" ";
	    					break;
						}
						else
						{
							cout<<endl<<"Not added to cluster"<<endl;
						}
					}
				}
			}
			cout<<endl;
			cout<<endl;
			for(int j=0;j<a;j++)
			{
				edgeweight[j]=mata[index][j];
					if(j==foundindices[maxi] || j==foundindices[maxi+1] || j==index)
				{
					edgeweight[j]=0;
				}
					if(edgeweight[j]==0)
				{
					continue;
				}
				cout<<arr[index]<<" with "<<j+1<<" "<<edgeweight[j]<<endl;
			}
			int clusteredgeweight[a];
		
				for(int j=0;j<a;j++)
				{
					clusteredgeweight[j]=mata[foundindices[maxi]][j];
					if(j==foundindices[maxi] || j==foundindices[maxi+1] || j==index)
				{
					clusteredgeweight[j]=0;
				}
					if(clusteredgeweight[j]==0)
					{
						continue;
					}
					cout<<arr[foundindices[maxi]]<<" with "<<j+1<<" "<<clusteredgeweight[j]<<endl;
			
				}
			
			int clusteredgeweights[a];
		
				for(int j=0;j<a;j++)
				{
					clusteredgeweights[j]=mata[foundindices[maxi+1]][j];
					if(j==foundindices[maxi] || j==foundindices[maxi+1] || j==index)
				{
					clusteredgeweights[j]=0;
				}
					if(clusteredgeweights[j]==0)
					{
						continue;
					}
					cout<<arr[foundindices[maxi+1]]<<" with "<<j+1<<" "<<clusteredgeweights[j]<<endl;
			
				}
			highestedge=0;
			highestedge=largest(edgeweight);
			if(largest(clusteredgeweight)>highestedge)
			{
				highestedge=largest(clusteredgeweight);
			}
			else if(largest(clusteredgeweights)>highestedge)
			{
				highestedge=largest(clusteredgeweights);
			}
			edgeindex=0;
			
			edgeindex=findindex(clusteredgeweights,highestedge);
			cout<<clusternodes<<" : "<<clusteredges<<endl;
			searchList(clusteredgeweights,highestedge);
				if(adjacency[foundindices[maxi]][foundindices[maxi+2]]==1)
			clusteredges++;
	  if(adjacency[foundindices[maxi+1]][foundindices[maxi+2]]==1)
			clusteredges++;
			
			maxi+=(clusternodes-1);
			for(int j=0;j<a;j++)
			{
				if(mata[index][edgeindex]==mata[index][j])
				{
						cout<<"hello fuvking nodesindfiajioafiojadf"<<endl;
				}
					if(adjacency[index][edgeindex]==adjacency[index][edgeindex+1])
					break;
			}
			if(adjacency[foundindices[maxi]][foundindices[maxi+1]]==1)
			clusteredges++;
			for (int max = maxi; max < foundindices.size(); max++)
			{
				for(int j=0;j<a;j++)
				{
					if(mata[index][edgeindex]==mata[index][j])
					{
						
						if((densityfunction(clusternodes,clusteredges,tdensity))&& (peripheryfunction(clusternodes,clusteredges,tperiphery)) && adjacency[index][edgeindex]==1)
						{
							cluster<<arr[foundindices[max]]<<" ";
							clusternodes++;
	    					break;
						}
						else
						{
							cout<<endl<<"Not added to cluster"<<endl;
						}
					}
				}
			}
			maxi=0;
			//third time
				cout<<endl;
			cout<<endl;
			for(int j=0;j<a;j++)
			{
				edgeweight[j]=mata[index][j];
								if(j==foundindices[maxi] || j==foundindices[maxi+1] || j==index || j==foundindices[maxi+2])
				{
					edgeweight[j]=0;
				}
					if(edgeweight[j]==0)
				{
					continue;
				}
				cout<<arr[index]<<" with "<<j+1<<" "<<edgeweight[j]<<endl;
			}
		
				for(int j=0;j<a;j++)
				{
					clusteredgeweight[j]=mata[foundindices[maxi]][j];
								if(j==foundindices[maxi] || j==foundindices[maxi+1] || j==index || j==foundindices[maxi+2])
				{
					clusteredgeweight[j]=0;
				}
					if(clusteredgeweight[j]==0)
					{
						continue;
					}
					cout<<arr[foundindices[maxi]]<<" with "<<j+1<<" "<<clusteredgeweight[j]<<endl;
			
				}
			
		
				for(int j=0;j<a;j++)
				{
					clusteredgeweights[j]=mata[foundindices[maxi+1]][j];
								if(j==foundindices[maxi] || j==foundindices[maxi+1] || j==index || j==foundindices[maxi+2])
				{
					clusteredgeweights[j]=0;
				}
					if(clusteredgeweights[j]==0)
					{
						continue;
					}
					cout<<arr[foundindices[maxi+1]]<<" with "<<j+1<<" "<<clusteredgeweights[j]<<endl;
			
				}
				
				int clusteredgeweight1[a];
				for(int j=0;j<a;j++)
				{
					clusteredgeweight1[j]=mata[foundindices[maxi+2]][j];
					if(j==foundindices[maxi] || j==foundindices[maxi+1] || j==index || j==foundindices[maxi+2])
				{
					clusteredgeweight1[j]=0;
				}
					if(clusteredgeweight1[j]==0)
					{
						continue;
					}
					cout<<arr[foundindices[maxi+2]]<<" with "<<j+1<<" "<<clusteredgeweight1[j]<<endl;
			
				}
			highestedge=0;
			edgeindex=0;
			highestedge=largest(edgeweight);
			edgeindex=findindex(edgeweight,highestedge);
			
			if(largest(clusteredgeweight)>=highestedge)
			{
				highestedge=largest(clusteredgeweight);
				edgeindex=findindex(clusteredgeweight,highestedge);
					searchList(clusteredgeweight,highestedge);
			}
			else if(largest(clusteredgeweights)>=highestedge)
			{
				highestedge=largest(clusteredgeweights);
				edgeindex=findindex(clusteredgeweights,highestedge);
					searchList(clusteredgeweights,highestedge);
			}
			else if(largest(clusteredgeweight1)>=highestedge)
			{
				highestedge=largest(clusteredgeweight1);
				edgeindex=findindex(clusteredgeweight1,highestedge);
					searchList(clusteredgeweight1,highestedge);
			}
			for(int i=0;i<foundindices.size();i++)
			{
				cout<<foundindices[i]<<endl;
			}
			maxi=0;
	
			
			if(adjacency[foundindices[maxi+1]][foundindices[maxi+3]]==1)
		clusteredges++;
		if(adjacency[foundindices[maxi+2]][foundindices[maxi+3]]==1)
						clusteredges++;
			maxi+=(clusternodes-1);
			for(int j=0;j<a;j++)
			{
				if(mata[index][edgeindex]==mata[index][j])
				{
						clusteredges++;
							clusternodes++;
				}
					if(adjacency[index][edgeindex]==adjacency[index][edgeindex+1])
					break;
			}
		
			for (int max = maxi; max < foundindices.size(); max++)
			{
				for(int j=0;j<a;j++)
				{
					if(mata[index][edgeindex]==mata[index][j])
					{
						
						if((densityfunction(clusternodes,clusteredges,tdensity))&& (peripheryfunction(clusternodes,clusteredges,tperiphery)) && adjacency[index][edgeindex]==1)
						{
							cluster<<arr[foundindices[max]]<<" ";
						
	    					break;
						}
						else
						{
							cout<<endl<<"Not added to cluster"<<endl;
						}
					}
				}
			}
						cout<<"nodesnodes"<<clusternodes<<endl;
			//fourth time
			
			cout<<endl;
			cout<<endl;
			maxi=0;
			for(int j=0;j<a;j++)
			{
				edgeweight[j]=mata[index][j];
			if(j==foundindices[maxi] || j==foundindices[maxi+1] || j==foundindices[maxi+2] || j==foundindices[maxi+3] || j==index )
				{
					edgeweight[j]=0;
				}
					if(edgeweight[j]==0)
				{
					continue;
				}
				cout<<arr[index]<<" with "<<j+1<<" "<<edgeweight[j]<<endl;
			}
		
				for(int j=0;j<a;j++)
				{
					clusteredgeweight[j]=mata[foundindices[maxi]][j];
				if(j==foundindices[maxi] || j==foundindices[maxi+1] || j==index || j==foundindices[maxi+2] || j==foundindices[maxi+3])
				{
					clusteredgeweight[j]=0;
				}
					if(clusteredgeweight[j]==0)
					{
						continue;
					}
					cout<<arr[foundindices[maxi]]<<" with "<<j+1<<" "<<clusteredgeweight[j]<<endl;
			
				}
			
		
				for(int j=0;j<a;j++)
				{
					clusteredgeweights[j]=mata[foundindices[maxi+1]][j];
					if(j==foundindices[maxi] || j==foundindices[maxi+1] || j==index || j==foundindices[maxi+2] || j==foundindices[maxi+3])
				{
					clusteredgeweights[j]=0;
				}
					if(clusteredgeweights[j]==0)
					{
						continue;
					}
					cout<<arr[foundindices[maxi+1]]<<" with "<<j+1<<" "<<clusteredgeweights[j]<<endl;
			
				}
				
				for(int j=0;j<a;j++)
				{
					clusteredgeweight1[j]=mata[foundindices[maxi+2]][j];
						if(j==foundindices[maxi] || j==foundindices[maxi+1] || j==index || j==foundindices[maxi+2] || j==foundindices[maxi+3])
				{
					clusteredgeweight1[j]=0;
				}
					if(clusteredgeweight1[j]==0)
					{
						continue;
					}
					cout<<arr[foundindices[maxi+2]]<<" with "<<j+1<<" "<<clusteredgeweight1[j]<<endl;
			
				}
				
				int clusteredgeweight2[a];
				for(int j=0;j<a;j++)
				{
					clusteredgeweight2[j]=mata[foundindices[maxi+3]][j];
					if(j==foundindices[maxi] || j==foundindices[maxi+1] || j==index || j==foundindices[maxi+2] || j==foundindices[maxi+3])
				{
					clusteredgeweight2[j]=0;
				}
					if(clusteredgeweight2[j]==0)
					{
						continue;
					}
					cout<<arr[foundindices[maxi+3]]<<" with "<<j+1<<" "<<clusteredgeweight2[j]<<endl;
			
				}
	
			highestedge=0;
			edgeindex=0;
			highestedge=largest(edgeweight);
			edgeindex=findindex(edgeweight,highestedge);

			if(largest(clusteredgeweight)>highestedge)
			{
				highestedge=largest(clusteredgeweight);
				edgeindex=findindex(clusteredgeweight,highestedge);
					searchList(clusteredgeweight,highestedge);
			}
			else if(largest(clusteredgeweights)>highestedge)
			{
				highestedge=largest(clusteredgeweights);
				edgeindex=findindex(clusteredgeweights,highestedge);
					searchList(clusteredgeweights,highestedge);
			}
			else if(largest(clusteredgeweight1)>highestedge)
			{
				highestedge=largest(clusteredgeweight1);
				edgeindex=findindex(clusteredgeweight1,highestedge);
					searchList(clusteredgeweight1,highestedge);
			}
			else if(largest(clusteredgeweight2)>highestedge)
			{
				highestedge=largest(clusteredgeweight2);
				edgeindex=findindex(clusteredgeweight2,highestedge);
					searchList(clusteredgeweight2,highestedge);
			}
		
	
			maxi+=(clusternodes-2);
		
			for (int max = maxi; max < foundindices.size(); max++)
			{
				for(int j=0;j<a;j++)
				{
					if(mata[index][edgeindex]==mata[index][j])
					{
						
						if((densityfunction(clusternodes,clusteredges,tdensity))&& (peripheryfunction(clusternodes,clusteredges,tperiphery)) && adjacency[index][edgeindex]==1)
						{
							cluster<<arr[foundindices[max]]<<" ";
						
	    					break;
						}
						else
						{
							cluster.close();
							cout<<"\nFile closed"<<endl;
							clusternodes--;
							cout<<arr[foundindices[max]]<<" not added to cluster"<<endl;
							break;
						}
					}
				}
			}
				cout<<clusternodes<<" : "<<clusteredges<<endl;
			foundindices[maxi]=0;
			
			for(int g=0;g<foundindices.size();g++)
			{
					for(int j=0;j<a;j++)
					{
						adjacency[foundindices[g]][j]=0;
						mata[foundindices[g]][j]=0;
					}
			
			}
		
			cout<<"After first cluster : "<<endl;
			for (int i=0;i<a;i++)
			{
				
				for(int j=0;j<a;j++)
				{
					cout<<adjacency[i][j]<<"\t";
				}
				cout<<endl;
			}
			for( kaka=0;kaka<a;kaka++)
			{
				for(villa=0;villa<a;villa++)
				{
					mata[kaka][villa]=0;	
				}
			}
				for(kaka=0; kaka<a; kaka++)
			{
				for(villa=0; villa<a; villa++)
				{
					sum=0;
					for(k=0; k<a; k++)
					{
						sum = sum + adjacency[kaka][k] * adjacency[k][villa];
					}
					mata[kaka][villa] = sum;
				}
			}	
			cout<<endl;
			cout<<"After M^2 :This is the weight of an edge "<<endl;
			
			
			for(int i=0;i<a;i++)
			{
				mata[i][i]=0;
			}
			
				
			for( kaka=0;kaka<a;kaka++)
			{
				for(villa=0;villa<a;villa++)
				{
					cout<<mata[kaka][villa]<<"\t";	
				}
				cout<<endl;
			}
			edges=0;
			for (int i=0;i<a;i++)
			{
				for(int j=0;j<a;j++)
				{
					if(adjacency[i][j]==1)
					{
						edges++;
					}
				}
			}
			gerrard=density(a,edges);
			for(int i=0;i<a;i++)
			{
			nodeweight[i]=0;
			}
			for( kaka=0;kaka<a;kaka++)
			{
				for(villa=0;villa<a;villa++)
				{
				sum=sum+mata[kaka][villa];	
				}
				nodeweight[kaka]=sum;
				cout<<"weight for node "<<arr[kaka]<<" is :"<<sum<<endl;
				
				sum=0;	
			}
			
			cout<<endl;
			degree=0;
			cout<<"degrees : "<<endl;
			
			for (int i=0;i<a;i++)
			{
				for(int j=0;j<a;j++)
					{
						degree+=adjacency[i][j];
					}
				degrees[i]=degree;
				cout<<"Degree for node "<<arr[i]<<" is :"<<degree<<endl;
				degree=0;
			}
			foundindices.clear();
			highest=0;
			index=0;
			
			highest=largest(nodeweight);
			index=findindex(nodeweight,highest);
			startnode=arr[index];
			
			for(int j=0;j<a;j++)
			{
				edgeweight[j]=mata[index][j];
					if(edgeweight[j]==0)
				{
					continue;
				}
				cout<<arr[index]<<" with "<<j+1<<" "<<edgeweight[j]<<endl;
			
			}
			highestedge=0;
			edgeindex=0;
			highestedge=largest(edgeweight);
			edgeindex=findindex(edgeweight,highestedge);
			cout<<highestedge<<"is highest edge and the edge index is"<<edgeindex<<endl;
			clusternodes=1;
			clusteredges=0;
			cout<<"weight = "<<highestedge<<" at "<<edgeindex<<" for node "<<arr[edgeindex];
			ofstream secondcluster("secondcluster.txt");
			secondcluster<<"second cluster starts by node "<<startnode<<endl<<"Adjacent nodes are : "<<endl;
			searchList(edgeweight,highestedge);
			maxi=0;
			
			for(int j=0;j<a;j++)
			{
				if(mata[index][edgeindex]==mata[index][j])
				{
					clusternodes++;	
					clusteredges++;
				}
					if(adjacency[index][edgeindex]==adjacency[index][edgeindex+1])
					break;
			}
			if(adjacency[foundindices[maxi]][foundindices[maxi+1]]==1)
			clusteredges++;
			
			for (int max = 0; max < foundindices.size(); max++)
			{
				for(int j=0;j<a;j++)
				{
					if(mata[index][edgeindex]==mata[index][j])
					{
						if((densityfunction(clusternodes,clusteredges,tdensity))&& (peripheryfunction(clusternodes,clusteredges,tperiphery)) && adjacency[index][edgeindex]==1)
						{
							secondcluster<<arr[foundindices[max]]<<" ";
	    					break;
						}
						else
						{
							cout<<endl<<"Not added to cluster"<<endl;
							break;
						}
					}
				}
			}
				cout<<"\nhalohelo"<<index<<endl;
			cout<<endl;
			cout<<endl;
			
			cout<<"after second cluster"<<endl;
				for(int j=0;j<a;j++)
					{
						adjacency[index][j]=0;
						mata[index][j]=0;
					}
			
			
		
			cout<<"After first cluster : "<<endl;
			for (int i=0;i<a;i++)
			{
				
				for(int j=0;j<a;j++)
				{
					cout<<adjacency[i][j]<<"\t";
				}
				cout<<endl;
			}
			for( kaka=0;kaka<a;kaka++)
			{
				for(villa=0;villa<a;villa++)
				{
					mata[kaka][villa]=0;	
				}
			}
				for(kaka=0; kaka<a; kaka++)
			{
				for(villa=0; villa<a; villa++)
				{
					sum=0;
					for(k=0; k<a; k++)
					{
						sum = sum + adjacency[kaka][k] * adjacency[k][villa];
					}
					mata[kaka][villa] = sum;
				}
			}	
			cout<<endl;
			cout<<"After M^2 :This is the weight of an edge "<<endl;
			
			
			for(int i=0;i<a;i++)
			{
				mata[i][i]=0;
			}
			
				
			for( kaka=0;kaka<a;kaka++)
			{
				for(villa=0;villa<a;villa++)
				{
					cout<<mata[kaka][villa]<<"\t";	
				}
				cout<<endl;
			}
			edges=0;
			for (int i=0;i<a;i++)
			{
				for(int j=0;j<a;j++)
				{
					if(adjacency[i][j]==1)
					{
						edges++;
					}
				}
			}
			gerrard=density(a,edges);
			for(int i=0;i<a;i++)
			{
			nodeweight[i]=0;
			}
			for( kaka=0;kaka<a;kaka++)
			{
				for(villa=0;villa<a;villa++)
				{
				sum=sum+mata[kaka][villa];	
				}
				nodeweight[kaka]=sum;
				cout<<"weight for node "<<arr[kaka]<<" is :"<<sum<<endl;
				
				sum=0;	
			}
			
			cout<<endl;
			degree=0;
			cout<<"degrees : "<<endl;
			
			for (int i=0;i<a;i++)
			{
				for(int j=0;j<a;j++)
					{
						degree+=adjacency[i][j];
					}
				degrees[i]=degree;
				cout<<"Degree for node "<<arr[i]<<" is :"<<degree<<endl;
				degree=0;
			}
			foundindices.clear();
			highest=0;
			index=0;
			
			highest=largest(nodeweight);
			index=findindex(nodeweight,highest);
			startnode=arr[index];
			
			for(int j=0;j<a;j++)
			{
				edgeweight[j]=mata[index][j];
					if(edgeweight[j]==0)
				{
					continue;
				}
				cout<<arr[index]<<" with "<<j+1<<" "<<edgeweight[j]<<endl;
			
			}
			highestedge=0;
			edgeindex=0;
			highestedge=largest(edgeweight);
			edgeindex=findindex(edgeweight,highestedge);
			cout<<highestedge<<"is highest edge and the edge index is"<<edgeindex<<endl;
			clusternodes=1;
			clusteredges=0;
			cout<<"weight = "<<highestedge<<" at "<<edgeindex<<" for node "<<arr[edgeindex];
			ofstream thirdcluster("thirdcluster.txt");
			thirdcluster<<"third cluster starts by node "<<startnode<<endl<<"Adjacent nodes are : "<<endl;
			searchList(edgeweight,highestedge);
			maxi=0;
			
			for(int j=0;j<a;j++)
			{
				if(mata[index][edgeindex]==mata[index][j])
				{
					clusternodes++;	
					clusteredges++;
				}
					if(adjacency[index][edgeindex]==adjacency[index][edgeindex+1])
					break;
			}
			if(adjacency[foundindices[maxi]][foundindices[maxi+1]]==1)
			clusteredges++;
			
			for (int max = 0; max < foundindices.size(); max++)
			{
				for(int j=0;j<a;j++)
				{
					if(mata[index][edgeindex]==mata[index][j])
					{
						if((densityfunction(clusternodes,clusteredges,tdensity))&& (peripheryfunction(clusternodes,clusteredges,tperiphery)) && adjacency[index][edgeindex]==1)
						{
							thirdcluster<<arr[foundindices[max]]<<" ";
	    					break;
						}
						else
						{
							cout<<endl<<"Not added to cluster"<<endl;
							break;
						}
					}
				}
			}
			cout<<"after third cluster"<<endl;
				for(int j=0;j<a;j++)
					{
						adjacency[index][j]=0;
						mata[index][j]=0;
					}
			
			
		
		
			for( kaka=0;kaka<a;kaka++)
			{
				for(villa=0;villa<a;villa++)
				{
					mata[kaka][villa]=0;	
				}
			}
				for(kaka=0; kaka<a; kaka++)
			{
				for(villa=0; villa<a; villa++)
				{
					sum=0;
					for(k=0; k<a; k++)
					{
						sum = sum + adjacency[kaka][k] * adjacency[k][villa];
					}
					mata[kaka][villa] = sum;
				}
			}	
			cout<<endl;
			cout<<"After M^2 :This is the weight of an edge "<<endl;
			
			
			for(int i=0;i<a;i++)
			{
				mata[i][i]=0;
			}
			
				for( kaka=0;kaka<a;kaka++)
			{
				for(villa=0;villa<a;villa++)
				{
					if(mata[kaka][villa]==0)
					{
						adjacency[kaka][villa]=0;
						}	
				}
				cout<<endl;
			}
			
				for (int i=0;i<a;i++)
			{
				
				for(int j=0;j<a;j++)
				{
					cout<<adjacency[i][j]<<"\t";
				}
				cout<<endl;
			}
			for( kaka=0;kaka<a;kaka++)
			{
				for(villa=0;villa<a;villa++)
				{
					cout<<mata[kaka][villa]<<"\t";	
				}
				cout<<endl;
			}
			edges=0;
			
			for (int i=0;i<a;i++)
			{
				for(int j=0;j<a;j++)
				{
					if(adjacency[i][j]==1)
					{
						edges++;
					}
				}
			}
			gerrard=density(a,edges);
			for(int i=0;i<a;i++)
			{
			nodeweight[i]=0;
			}
			for( kaka=0;kaka<a;kaka++)
			{
				for(villa=0;villa<a;villa++)
				{
				sum=sum+mata[kaka][villa];	
				}
				nodeweight[kaka]=sum;
				cout<<"weight for node "<<arr[kaka]<<" is :"<<sum<<endl;
				
				sum=0;	
			}
			
			cout<<endl;
			degree=0;
			cout<<"degrees : "<<endl;
			
			for (int i=0;i<a;i++)
			{
				for(int j=0;j<a;j++)
					{
						degree+=adjacency[i][j];
					}
				degrees[i]=degree;
				cout<<"Degree for node "<<arr[i]<<" is :"<<degree<<endl;
				
			}
			if(degree==0)
			{
				cout<<"ERROR!!!! NO MORE CLUSTERS CAN BE FORMED The degree is zero program is ending"<<endl;
			}
			else
			{
			
			foundindices.clear();
			highest=0;
			index=0;
			
			highest=largest(nodeweight);
			index=findindex(nodeweight,highest);
			startnode=arr[index];
			
			for(int j=0;j<a;j++)
			{
				edgeweight[j]=mata[index][j];
					if(edgeweight[j]==0)
				{
					continue;
				}
				cout<<arr[index]<<" with "<<j+1<<" "<<edgeweight[j]<<endl;
			
			}
			highestedge=0;
			edgeindex=0;
			highestedge=largest(edgeweight);
			edgeindex=findindex(edgeweight,highestedge);
			cout<<highestedge<<"is highest edge and the edge index is"<<edgeindex<<endl;
			clusternodes=1;
			clusteredges=0;
			cout<<"weight = "<<highestedge<<" at "<<edgeindex<<" for node "<<arr[edgeindex];
			ofstream fourthcluster("fourthcluster.txt");
			fourthcluster<<"fourth cluster starts by node "<<startnode<<endl<<"Adjacent nodes are : "<<endl;
			searchList(edgeweight,highestedge);
			maxi=0;
			
			for(int j=0;j<a;j++)
			{
				if(mata[index][edgeindex]==mata[index][j])
				{
					clusternodes++;	
					clusteredges++;
				}
					if(adjacency[index][edgeindex]==adjacency[index][edgeindex+1])
					break;
			}
			if(adjacency[foundindices[maxi]][foundindices[maxi+1]]==1)
			clusteredges++;
			
			for (int max = 0; max < foundindices.size(); max++)
			{
				for(int j=0;j<a;j++)
				{
					if(mata[index][edgeindex]==mata[index][j])
					{
						if((densityfunction(clusternodes,clusteredges,tdensity))&& (peripheryfunction(clusternodes,clusteredges,tperiphery)) && adjacency[index][edgeindex]==1)
						{
							fourthcluster<<arr[foundindices[max]]<<" ";
	    					break;
						}
						else
						{
							cout<<endl<<"Not added to cluster"<<endl;
							break;
						}
					}
				}
			}
			
			
		}
		}
			

