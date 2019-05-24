#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class node{
 public:
  /**
   *\fn node(string n)
   *\brief constructor for a graph node
   *
   *creates a node and sets n as the name of the new node
   *
   *\param n name of the node to be created
   *
   */
  node(string n);
  /**
   *\fn addAdj(node* n)
   *\brief adds a node to a specific node's adjacency vector
   *
   *\param n the node to be added to the node's adjacency vector
   *
   */
  void addAdj(node* n);
  /**
   *var vector<node*> adjList
   *\brief vector to hold all of the adjacent nodes
   *
   */
  vector<node*> adjList;
  /**
   *var string name
   *\brief string that holds the name of a node
   *
   */
  string name;
  /**
   *\var int indegree
   *\brief holds the indegree of the node
   *
   */
  int indegree;
};

node::node(string n){
  name=n;
  indegree=0;}

void node::addAdj(node* n){
  adjList.push_back(n);
}

vector<node*> nodeList;

/**
 *\fn void topological()
 *\brief topologically sorts a graph
 *
 *Uses an algorithm similar to the Weiss/powerpoint algorith
 *describes in the slides.  Prints the result to the screen.
 *
 */
void topological();

// we want to use parameters
int main (int argc, char **argv) {

  // verify the correct number of parameters
  if ( argc != 2 ) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }

  // attempt to open the supplied file
  ifstream file(argv[1], ifstream::binary);

  // report any problems opening the file and then exit
  if ( !file.is_open() ) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }

  // read in two strings
  while (file.good()){
  string s1, s2;
  //bool bool2=true;
  bool check1=false;
  bool check2=false;
  int indexs1=0;
  int indexs2=0;
  file >> s1;
  file >> s2;
  if(s1=="0" && s2=="0")
    break;

  for(int i=0;i<nodeList.size();i++){
    if(nodeList[i]->name==s1){
        indexs1=i;
        check1=true;}
  }
  if(check1==false){
     node* temp1=new node(s1);
     nodeList.push_back(temp1);
     indexs1=nodeList.size()-1;}

  for(int j=0;j<nodeList.size();j++){
    if(nodeList[j]->name==s2){
        indexs2=j;
        check2=true;}
  }

 if(check2==false){
     node* temp2=new node(s2);
     nodeList.push_back(temp2);
     indexs2=nodeList.size()-1;}
  
  nodeList[indexs2]->indegree++;//increase indegree of s2
  nodeList[indexs1]->addAdj(nodeList[indexs2]);}//add s2 to adj list for s1

  topological();

  // close the file before exiting
  file.close();} 
  

void topological(){
  queue<node*> q;
  node *temp3;
  node *temp4;
  
  for(int i=0;i<nodeList.size();i++){
    temp3=nodeList[i];
    if(temp3->indegree==0)
      q.push(temp3);
  }

  while(q.empty()==false){
    temp3=q.front();
    q.pop();
    cout<<temp3->name<<" ";
    for(int j=0;j<temp3->adjList.size();j++){
      temp4=temp3->adjList[j];
      temp4->indegree--;
      if(temp4->indegree==0)
    q.push(temp4);
    }
  }

  cout<<endl;}