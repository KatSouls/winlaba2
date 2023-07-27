package com.company;

public class Median {
    private Point end;
    private Point begin;

    public void setEnd(Point end) {
        this.end = end;
    }

    public Point getEnd() {
        return end;
    }

    public void setBegin(Point begin) {
        this.begin = begin;
    }

    public Point getBegin() {
        return begin;
    }
    public Median(Point top, Point point){
        this.begin = top;
        this.begin = point;
    }
}
