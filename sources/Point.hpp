


namespace ariel
{

    using namespace std;

    class Point{
      private:
         double x;
         double y;

      public:
        Point(double, double);
        double distance(Point &Other);
        void print();
        friend Point moveTowards(Point &source, Point &destenation, double distance);


        

    

    }
}
