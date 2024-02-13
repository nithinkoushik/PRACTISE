import java.util.Scanner;
class pattern<T>
{
    T a;
    pattern(T a)
    {
      this.a=a;  
    }
    void pat()
    {
        for(int i=0;i<5;i++)
        {
           for(int j=0;j<=i;j++)
           {
               System.out.print(a);
               
           }
        System.out.println();   
        }
    }
}
class Main 
{
    public static void main(String args[])
    {
        pattern<Integer>ob1=new pattern(1);
        pattern<String>ob2=new pattern("*");
        ob1.pat();
        ob2.pat();
    }
}
