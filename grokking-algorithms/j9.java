import java.util.HashMap; //ja tem hash table padrao

public class j9 {
    public static void main(String[] args) {
        //criar a tabela hash (hashmap) que associa a string a float
        HashMap<String, Float> book = new HashMap<>();

        //inserir itens (como no dict do python)    
        book.put("apple", 0.67f);
        book.put("milk", 1.49f);
        book.put("avocado", 2.32f);

        //imprimir o conteudo 
        System.out.println(book);

        //acessar o valor de "milk"
        System.out.println("milk price: " + book.get("milk"));

    }
}
