import java.io.*;


public class Main {

    public static void main(String[] args) {
        File file = new File("/Users/yvesbazin/Downloads/add.bmp");
        byte[] fileData = new byte[(int) file.length()];
        try {
            DataInputStream dis = new DataInputStream(new FileInputStream(file));
            dis.readFully(fileData);
            dis.close();
            // System.out.println("here");
            for (int i=0;i<fileData.length;i++) {

               // System.out.println(String.format("0x%02X ", fileData[i]));
            }

            int w=((int)fileData[18]<0) ? 256+ (int)fileData[18]-1:(int)fileData[18];
            int h=((int)fileData[22]<0) ? 256+ (int)fileData[22]-1:(int)fileData[22];
            System.out.println("taille x:"+w);
            System.out.println("taille y:"+h);
            System.out.println("offset:"+(fileData[10]+256*fileData[11]));
            int offset=(int)(fileData[10]+256*fileData[11]);
            //h=84;
            int de=4-3*w%4;
            if (de==4)
                de=0;
            w=w*3;
            System.out.println("decalage:"+de);
            //w=14*3;
           // h=15;
            //offset=0;
            for(int y=0;y<h;y++) {
                for (int x = 0; x < w/3; x++) {
                    System.out.print(String.format("0x%02X ", fileData[y*w+3*x+2+y*de+offset])+",");
                    System.out.print(String.format("0x%02X ", fileData[y*w+3*x+1+y*de+offset])+",");
                    System.out.print(String.format("0x%02X ", fileData[y*w+3*x+y*de+offset])+",");
                   // System.out.print(fileData[y*w+x+offset]+",");
                }//System.out.print("yves,");
                System.out.println();
            }

        } catch (IOException e){System.out.println(e.toString());}


        // write your code here
    }
}
