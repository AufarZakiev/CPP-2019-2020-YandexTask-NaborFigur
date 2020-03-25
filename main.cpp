#include <figures.h>
#include <memory>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

shared_ptr<Figure> CreateFigure(istringstream& is)
{
  shared_ptr<Figure> figure;
  string name;
  is >> name;
  if (name == "RECT")
  {
    int a, b;
    is >> a >> b;
    figure = make_shared<Rect>(a, b);
  }
  else if (name == "TRIANGLE")
  {
    int a, b, c;
    is >> a >> b >> c;
    figure = make_shared<Triangle>(a, b, c);
  }
  else
  {
    int a;
    is >> a;
    figure = make_shared<Circle>(a);
  }
  return figure;
}

int main()
{
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line);)
  {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD")
    {
      figures.push_back(CreateFigure(is));
    }
    else if (command == "PRINT")
    {
      for (const auto& current_figure : figures)
      {
        cout << fixed << setprecision(3) << current_figure->Name() << " " << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
