import java.io.FileWriter;

public class Codigo1TXT {

    public static void main(String[] args) {

        try {

            FileWriter archivo = new FileWriter("codigo1.txt");

            archivo.write("Hola Mundo");

            archivo.close();

            System.out.println("Archivo guardado");

        } catch (Exception e) {

            System.out.println("Error");
        }
    }
}
