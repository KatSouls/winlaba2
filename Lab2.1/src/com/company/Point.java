package com.company;

class Point {
    protected double x;
    protected double y;

    public Point(double x, double y){
        this.x = x;
        this.y = y;
    }

    public double Get_x(){
        return this.x;
    }

    public double Get_y(){
        return this.y;
    }

    public String Vivod(){
        return "("+x+","+y+")";
    }
}
