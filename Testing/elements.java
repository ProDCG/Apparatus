package Testing;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class elements {
    

    public static void main(String[] args) throws IOException {
        FileWriter myWriter = new FileWriter("elements.txt");
        Random rand = new Random();
        myWriter.write("[");
        for (int i = 0; i < 10000; i++) {
            myWriter.write(rand.nextInt(10001) + ", ");
        }
        myWriter.close();
    }
    
}
