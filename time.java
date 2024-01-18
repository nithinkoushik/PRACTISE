import java.util.Scanner;
class time{
    int hours,minutes,seconds;
    time(int hours,int minutes,int seconds)
    {
        this.hours=hours;
        this.minutes=minutes;
        this.seconds=seconds;
    }
    void advtime(int h,int m,int s)
    {
        seconds+=s;
        minutes+=m+(seconds/60);
        hours+=h+(minutes/60);
        
        seconds=seconds%60;
        minutes=minutes%60;
        hours=hours%60;
    }
    void currenttime(int h,int m,int s)
    {
        hours=h;
        minutes=m;
        seconds=s;
    }
    void print(){
        System.out.println("hours:"+hours);
           System.out.println("minutes:"+minutes);
              System.out.println("seconds:"+seconds);
    }
}
class Main 
{
  public static void main(String args[])
  {
      Scanner in=new Scanner(System.in);
      int hours,minutes,seconds;int advh,advm,advs;int curh,curm,curs;
        System.out.println("enter initial h m s");
        hours=in.nextInt();
        minutes=in.nextInt();
        seconds=in.nextInt();
      time ob=new time(hours,minutes,seconds);
       System.out.println("enter advanced time in h m s");
       advh=in.nextInt();
       advm=in.nextInt();
       advs=in.nextInt();
       ob.advtime(advh,advm,advs);
       System.out.println("advanced time:");
       ob.print();
       System.out.println("enter current time");
       curh=in.nextInt();
       curm=in.nextInt();
       curs=in.nextInt();
       ob.currenttime(curh,curm,curs);
       ob.print();
  }
}
