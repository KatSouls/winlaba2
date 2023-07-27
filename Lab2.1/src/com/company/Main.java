package com.company;
import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double a, b;
        do{
            System.out.println("Введите первую вершину");
            a = scan.nextDouble();
            b = scan.nextDouble();
        }while (a == b);
        Point point1 = new Point(a,b);
        do{
            System.out.println("Введите вторую вершину");
            a = scan.nextDouble();
            b = scan.nextDouble();
        }while (a == b || a == point1.x || b== point1.y);
        Point point2 = new Point(a,b);
        do{
            System.out.println("Введите третью вершину");
            a = scan.nextDouble();
            b = scan.nextDouble();
        }while (a == b || a == point1.x || b== point1.y || a == point2.x || b== point2.y);
        Point point3 = new Point(a,b);


        Segment s1 = new Segment(point1, point2);
        Segment s2 = new Segment(point1, point3);
        Segment s3 = new Segment(point2, point3);

        Median m1 = new Median(point1, s3.get_mid());
        Median m2 = new Median(point2, s2.get_mid());
        Median m3 = new Median(point3, s1.get_mid());

        System.out.println("Центр треугольника: "+Get_Mid_triangle(m1,m2,m3).Vivod());
    }
    public static Point Get_Mid_triangle(Median one, Median two, Median three){
        return new Point((one.getBegin().x + two.getBegin().x + three.getBegin().x)/3,
                (one.getBegin().y + two.getBegin().y + three.getBegin().y)/3);
    }
}
