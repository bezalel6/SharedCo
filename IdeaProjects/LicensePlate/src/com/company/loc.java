package com.company;

public class loc{
    private int value,id,ogNumIndex1,ogNumIndex2;
    private boolean isOgNum=false;
    private String calc;
    public loc(int value, int id) {
        this.calc = value+"";
        this.value = value;
        isOgNum=true;
        this.id = id;
    }
    public loc(int value, int id, int ogNumIndex1, int ogNumIndex2,String calc) {
        this.value = value;
        this.calc=calc;
        this.id = id;
        this.ogNumIndex1 = ogNumIndex1;
        this.ogNumIndex2 = ogNumIndex2;
    }

    public String getCalc() {
        return calc;
    }

    @Override
    public String toString() {
        return "loc{" +
                "value=" + value +
                ", id=" + id +
                ", ogNumIndex1=" + ogNumIndex1 +
                ", ogNumIndex2=" + ogNumIndex2 +
                ", isOgNum=" + isOgNum +
                ", calc='" + calc + '\'' +
                '}';
    }

    public boolean isOgNum() {
        return isOgNum;
    }

    public int getOgNumIndex1() {
        return ogNumIndex1;
    }

    public int getOgNumIndex2() {
        return ogNumIndex2;
    }



    public int getValue() {
        return value;
    }

    public int getId() {
        return id;
    }

}