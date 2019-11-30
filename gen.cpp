#include <iostream>
using std::endl;
using std::cout;
#include <cstdlib>
#include <cstring>
#include <random>

//call this with

//    exe <low bound> <high bound>

int main(int argc, char const *argv[])
{
  //random number generation
  std::random_device rd;
  std::mt19937 mt(rd());

  if(!strcmp(argv[1], std::string("float").c_str()))
  {
    // cout << "floating point" << endl;
    std::uniform_real_distribution<float> dist(atof(argv[2]), atof(argv[3]));
    //output some samples
    cout << dist(mt) <<  " " << dist(mt) << " " << dist(mt) << endl;
  }
  else if(!strcmp(argv[1], std::string("int").c_str()))
  {
    // cout << "integer" << endl;
    std::uniform_int_distribution<int> dist(atoi(argv[2]), atoi(argv[3]));
    //output some samples
    cout << dist(mt) <<  " " << dist(mt) << " " << dist(mt) << endl;
  }
  else if(!strcmp(argv[1], std::string("list").c_str()))
  {
    std::uniform_int_distribution<int> dist1(atoi(argv[4]), atoi(argv[5])); //input values
    std::uniform_int_distribution<int> dist2(0,atoi(argv[2])-1);  //nodes

    cout << 1 << endl;

    int num_nodes = atoi(argv[2]);
    int num_links = atoi(argv[3]);

    cout << num_nodes << " " << num_links  << endl; //number of nodes, number of links

    for(int i = 0; i < num_links; i++)
    {
      cout << dist2(mt) << " " << dist2(mt) << " " << dist1(mt) << endl;  //first node, second node, weight
    }
  }

  return 0;
}
