package ver_Date;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Person p[] = new Person[4];
        p[0] = new Person("AAA",12,23,'F');
        p[1] = new Person("CCC",12,23,'F');
        p[2] = new Person("DDD",12,23,'F');
        p[3] = new Person("BBB",12,23,'F');
        sortByNames(p);
        printPersons(p);
    }

    public static void printPersons(Person[] a)
    {
        for (int i=0;i<a.length;i++) System.out.println(a[i]);
    }
    public static void checkAndPrint(Person[] a)
    {
        for (int i = 0; i <a.length ; i++) {
            if(a[i].getId()%10%2==0&&a[i].getName().length()>10)
                System.out.println(a[i]);
        }
    }
    public static String getNameOfBiggestPerson(Person[] a)
    {
        double max=0;
        int index=0;
        for (int i = 0; i <a.length ; i++) {
            if(a[i].getAge()>max)
            {
                max = a[i].getAge();
                index = i;
            }
        }
        return a[index].getName();
    }
    public static int getNumOfFeMales(Person[] a)
    {
        int counter=0;
        for (int i = 0; i < a.length; i++) {
            if(a[i].getGender()=='F')counter++;
        }
        return counter;
    }
    public static  String[] getNamesOfFemalesOver15(Person[] a)
    {
        ArrayList arr = new ArrayList();
        for (int i = 0; i < a.length; i++) {
            if(a[i].getGender()=='F'&&a[i].getAge()>15) arr.add(a[i].getName());
        }
        String stringArr[] = new String[arr.size()];
        for (int i = 0; i <arr.size() ; i++) {
            stringArr[i]=arr.get(i).toString();
        }
        return stringArr;
    }
    public static void sortByNames(Person[] a)
    {
        for (int i = 0; i < a.length-1; i++) {
            for (int j = 0; j < a.length-i-1; j++) {
                if(a[j].getName().compareTo(a[j+1].getName())>0) {
                    Person temp = a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
    }
}
