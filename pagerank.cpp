#include <iostream>
#include "graph.h"
#include "program.h"
#include "error.h"
#include <fstream>

using namespace std;
using namespace simit;

int main(int argc, char **argv) {

  if (argc != 3) {
    std::cerr << "Usage: springs <path to simit code> <path to data>" << std::endl;
    return -1;
  }
  std::string codefile = argv[1];
  std::string datafile = argv[2];

  simit::init("cpu", sizeof(double));

  std::ifstream datafileStream(datafile);
    
  // Pages
  Set pages;
  FieldRef<double> outlinks = pages.addField<double>("outlinks");
  FieldRef<double> pr = pages.addField<double>("pr");
  
  // Links
  Set links(pages,pages);

  std::vector<ElementRef> elements;

  // Add pages
  int from, to;
  std::cout << "read file" << std::endl;
  while (datafileStream >> from >> to)
  {
      int maxPage = max(from, to);
      while(pages.getSize()-1 < maxPage)
      {
        //std::cout << "add: " << pages.getSize() << std::endl;
        auto page = pages.add();
        pr(page) = 1.0;
        elements.push_back(page);
        outlinks(page) = 0;
      }
      outlinks(elements[from]) = outlinks(elements[from]) + 1;
      links.add(elements[from], elements[to]);
  }

  // Compile program and bind arguments
  Program program;
  program.loadFile(codefile);

  Function func = program.compile("main");

  func.bind("pages", &pages);
  func.bind("links", &links);
  std::cout << "init program" << std::endl;

  func.init();
  func.unmapArgs();

  std::cout << "run program" << std::endl;

  func.run();
  func.mapArgs();
  
  // for(auto page: pages)
  // {
  //   std::cout << (float) pr.get(page) << " ";
  // }
  // std::cout << std::endl;
}
