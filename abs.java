import java.util.Scanner;
abstract class figure
{
    double dim1,dim2;double result;
    figure(double a,double b)
    {
        dim1=a;
        dim2=b;
    }
    abstract double area();
}
class rectangle extends figure  {
     rectangle(double a,double b)
     {
         super(a,b);
     }
    double area()
    {
       result= dim1*dim2;
       return result;
    }
}
class triangle extends figure
{
    triangle(double a,double b)
     {
         super(a,b);
     }
    double area()
    {
       result= 0.5*dim1*dim2;
       return result;
    }
}
class Main {
    public static void main(String args[])
    {
        double length,breadth;double height,base;double res1,res2;
        Scanner in=new Scanner(System.in);
        System.out.println("enter values of l and b");
        length=in.nextDouble();
        breadth=in.nextDouble();
       rectangle ob1=new rectangle(length,breadth);
       System.out.println("enter values of h and b");
       height=in.nextDouble();
       base=in.nextDouble();
       triangle ob2=new triangle(height,base);
      res1= ob1.area();
      res2= ob2.area();
      System.out.println("area of rectangle"+res1);
      System.out.println("area of triangle"+res2);
    }
}
