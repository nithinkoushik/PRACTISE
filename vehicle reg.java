import java.util.Scanner;
class vehicle
{
    int reg_num,price;
    static int count=0;
    vehicle()
    {
        count++;
        System.out.println("vehicle "+count+"created");
    }
    void getregno()
    {
        Scanner in=new Scanner(System.in);
        System.out.println("enter reg number ");
        reg_num=in.nextInt();
        System.out.println("enter price  ");
        price=in.nextInt();
    }
    void setregno()
    {
        System.out.println("the vehicle registration number:"+reg_num);
        System.out.println("the price of the vehicle:"+price);
    }
    static void getvehiclecount()
    {
        System.out.println("the number of vehicles in the garage:"+count);
    }
    
    
}
class Main 
{
    public static void main(String args[])
    {
    int n;
    Scanner in=new Scanner(System.in);
    System.out.println("enter the number of vehicles");
    n=in.nextInt();
    vehicle ob[]=new vehicle[n];
    for(int i=0;i<n;i++)
    {
        ob[i]=new vehicle();
        ob[i].getregno();
        ob[i].setregno();
    }
    vehicle.getvehiclecount();
}
}
