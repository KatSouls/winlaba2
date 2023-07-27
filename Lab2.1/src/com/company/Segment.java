package com.company;

public class Segment {
    private Point begin;
    private Point end;

    public Point getBegin() {
        return begin;
    }
    public void setBegin(Point begin) {
        this.begin = begin;
    }

    public Point getEnd() {
        return end;
    }
    public void setEnd(Point end) {
        this.end = end;
    }

    public Point get_mid(){
        return new Point((this.begin.x+this.end.x)/2,(this.begin.y+this.end.y)/2);
    }

    public Segment(Point begin, Point end){
        this.begin = begin;
        this.end = end;
    }
}
