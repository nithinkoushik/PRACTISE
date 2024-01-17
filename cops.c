import java.util.Scanner;
class student
{
    Scanner in=new Scanner(System.in);
    String usn,name;
    int credits[];
    int marks[] ;
    int grade[] ;
    int n;int totcredits;int tot;
   double gpa;
    student(String usn,String name)
    {
        this.usn=usn;
        this.name=name;
    }
    void getMarks()
    {
        System.out.println("enter the number of subjects");
        n=in.nextInt();
        credits=new int[n];
         marks=new int[n];
          grade=new int[n];
        
        for(int i=0;i<n;i++)
        {
             System.out.println("enter the credits of subject"+(i+1));
             credits[i]=in.nextInt();
             System.out.println("enter the marksof subject"+(i+1));
             marks[i]=in.nextInt();
        }
        
    }
    void compute()
    {
        for(int i=0;i<n;i++)
        {
            if(marks[i]>=90 && marks[i]<=100)
            grade[i]=10;
            else if(marks[i]>=80 && marks[i]<90)
            grade[i]=9;
             else if(marks[i]>=70 && marks[i]<80)
            grade[i]=8;
             else if(marks[i]>=60 && marks[i]<70)
            grade[i]=7;
             else if(marks[i]>=50 && marks[i]<60)
            grade[i]=6;
            else
            grade[i]=0;
        }
         
    
    
}
void sgpa()
{
    
    for(int i=0;i<n;i++)
    totcredits+=credits[i];
    for(int i=0;i<n;i++)
    {
        tot+=credits[i]*grade[i];
    }
    gpa=tot/totcredits;
    System.out.println(usn);
    System.out.println(name);
    System.out.println(gpa);
}
}
class Main 
{
    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        String name,usn;
         System.out.println("enter name usn");
         name=in.next();
         usn=in.next();
         student ob=new student(name,usn);
         ob.getMarks();
         ob.compute();
         ob.sgpa();
    }
}
