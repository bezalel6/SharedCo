package com.company;

import java.util.ArrayList;

public class Main {
    static ArrayList store = new ArrayList();
    static int[] arr = {3,5,8,4,78};
    public static void main(String[] args) {
        int count = 0;

        int sum = getSum(arr, 0, arr.length);

        createStore();

        System.out.println(store.size()+" size 1");
        String result = "";
        ArrayList storeFoundNums = new ArrayList();
        for (int i = 0; i < store.size() ; i++) {
            loc a = (loc)store.get(i);
            for (int j = 0; j < store.size()&&i!=j ; j++) {
                loc b = (loc)store.get(j);
                if(a.getId()!=b.getId()&&!storeFoundNums.contains(a.getOgNumIndex1())&&!storeFoundNums.contains(b.getOgNumIndex1()))
                {

                    if(a.getValue()-b.getValue()==0||a.getValue()+b.getValue()==0||b.getValue()-a.getValue()==0)
                    {




                        store.remove(a);
                        store.remove(b);
                        try{
                            int aindex1 = store.lastIndexOf(arr[a.getOgNumIndex1()]),aindex2 = store.lastIndexOf(arr[a.getOgNumIndex2()]);
                            int bindex1 = store.lastIndexOf(arr[a.getOgNumIndex1()]),bindex2 = store.lastIndexOf(arr[a.getOgNumIndex2()]);
                            store.remove(aindex1);
                            store.remove(bindex1);

                            store.remove(aindex2);
                            store.remove(bindex2);
                        }
                        catch (Exception e){
                            System.out.println(e.toString());
                        }

                        arr[a.getOgNumIndex2()]=-1;
                        arr[b.getOgNumIndex2()]=-1;

                        arr[a.getOgNumIndex1()]=-1;
                        arr[b.getOgNumIndex1()]=-1;

                        storeFoundNums.add(a.getOgNumIndex1());
                        storeFoundNums.add(a.getOgNumIndex2());


                        storeFoundNums.add(b.getOgNumIndex2());
                        storeFoundNums.add(b.getOgNumIndex2());
                    }
                    if(a.getValue()-b.getValue()==0) {

                        result+="a = "+a.getCalc()+"  b = "+b.getCalc()+"  "+a.getValue()+"-"+b.getValue()+"\n";
                    }
                    else if(a.getValue()+b.getValue()==0)
                    {

                        result+="a = "+a.getCalc()+"  b = "+b.getCalc()+"  "+a.getValue()+"+"+b.getValue()+"\n";
                    }
                    else if(b.getValue()-a.getValue()==0)
                    {

                        result+="a = "+a.getCalc()+"  b = "+b.getCalc()+"  "+b.getValue()+"-"+a.getValue()+"\n";
                    }

                }
            }
        }
        System.out.println(store.size()+" size 2");

        for (int i = 0; i < arr.length ; i++) {
            System.out.println(arr[i]);
        }

        for (int i = 0; i <storeFoundNums.size() ; i++) {
            arr[(int)storeFoundNums.get(i)]=-1;
        }
        System.out.println(result);

        boolean found=false;
        for (int i = 0; i < arr.length; i++) {
            if(arr[i]!=-1)found=true;
        }
        if(found) System.out.println("cannot calculate");
        else System.out.println("Can Calculate");
    }
    static void createStore()
    {

        for (int i = 0; i < arr.length ; i++) {
            store.add(new loc(arr[i],id()));
        }

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length&&i!=j ; j++) {
                store.add(new loc(arr[i]+arr[j],id(),i,j,arr[i]+" + "+arr[j]));
            }
        }
        //חיבור

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length&&i!=j ; j++) {
                store.add(new loc(arr[i]-arr[j],id(),i,j,arr[i]+" - "+arr[j]));
            }
        }
        //חיסור a-b


        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length&&i!=j ; j++) {
                store.add(new loc(arr[j]-arr[i],id(),j,i,arr[j]+" - "+arr[i]));
            }
        }//חיסור b-a

    }
    
    static int getSum(int[] arr, int start, int end) {
        int sum = arr[start];
        for (int j = start+1; j < end; j++) {
            sum += arr[j];
        }
        return sum;
    }

    static int getNum(int[] arr, int start, int end) {
        int num = arr[start];
        for (int i = start + 1; i <= end; i++) {
            num *= 10;
            num += arr[i];
        }
        return num;
    }
    static int Id=0;
    static int id()
    {
        Id++;
        return Id-1;
    }
}

