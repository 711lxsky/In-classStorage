package OMWork6;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

// 图书馆管理系统
public class LibraryManagementSystem {
    
    // 图书类
    static class Book {
        String title;  // 书名
        ArrayList<String> authors;  // 作者
        String publisher;  // 出版社
        int quantity;  // 馆藏数量
        
        // 构造函数
        public Book(String title, ArrayList<String> authors, String publisher, int quantity) {
            this.title = title;
            this.authors = authors;
            this.publisher = publisher;
            this.quantity = quantity;
        }
    }
    
    // 图书馆类
    static class Library {
        Map<String, ArrayList<Book>> booksByTitle;  // 书名对应的书籍列表
        Map<String, ArrayList<Book>> booksByAuthor;  // 作者对应的书籍列表
        Map<String, ArrayList<Book>> booksByPublisher;  // 出版社对应的书籍列表
        Map<String, Integer> borrowedBooksCount;  // 同学借阅书籍数量
        
        // 构造函数
        public Library() {
            booksByTitle = new HashMap<>();
            booksByAuthor = new HashMap<>();
            booksByPublisher = new HashMap<>();
            borrowedBooksCount = new HashMap<>();
        }
        
        // 添加书籍
        public void addBook(Book book) {
            // 检查是否已存在同名书籍
            if (booksByTitle.containsKey(book.title)) {
                ArrayList<Book> existingBooks = booksByTitle.get(book.title);
                // 遍历已存在的同名书籍列表，检查是否存在相同的作者和出版社
                for (Book existingBook : existingBooks) {
                    if (existingBook.authors.equals(book.authors) && existingBook.publisher.equals(book.publisher)) {
                        // 存在相同的作者和出版社，增加书籍数量
                        existingBook.quantity += book.quantity;
                        return;
                    }
                }
                // 不存在相同的作者和出版社，将新的书籍加入同名书籍列表
                existingBooks.add(book);
            } else {
                // 不存在同名书籍，创建新的同名书籍列表，并加入书籍
                ArrayList<Book> newBooks = new ArrayList<>();
                newBooks.add(book);
                booksByTitle.put(book.title, newBooks);
            }
            
            // 将书籍按作者添加到booksByAuthor中
            for (String author : book.authors) {
                if (booksByAuthor.containsKey(author)) {
                    booksByAuthor.get(author).add(book);
                } else {
                    ArrayList<Book> newBooks = new ArrayList<>();
                    newBooks.add(book);
                    booksByAuthor.put(author, newBooks);
                }
            }
            
            // 将书籍按出版社添加到booksByPublisher中
            if (booksByPublisher.containsKey(book.publisher)) {
                booksByPublisher.get(book.publisher).add(book);
            } else {
                ArrayList<Book> newBooks = new ArrayList<>();
                newBooks.add(book);
                booksByPublisher.put(book.publisher, newBooks);
            }
        }
        
        // 删除书籍
        public void removeBook(Book book) {
            // 检查书籍是否存在借阅情况
            if (borrowedBooksCount.containsKey(book.title)) {
                System.out.println("无法删除书籍：" + book.title + "，存在借阅情况。");
                return;
            }
            
            // 从booksByTitle中删除书籍
            if (booksByTitle.containsKey(book.title)) {
                ArrayList<Book> existingBooks = booksByTitle.get(book.title);
                existingBooks.remove(book);
                if (existingBooks.isEmpty()) {
                    booksByTitle.remove(book.title);
                }
            }
            
            // 从booksByAuthor中删除书籍
            for (String author : book.authors) {
                if (booksByAuthor.containsKey(author)) {
                    ArrayList<Book> existingBooks = booksByAuthor.get(author);
                    existingBooks.remove(book);
                    if (existingBooks.isEmpty()) {
                        booksByAuthor.remove(author);
                    }
                }
            }
            
            // 从booksByPublisher中删除书籍
            if (booksByPublisher.containsKey(book.publisher)) {
                ArrayList<Book> existingBooks = booksByPublisher.get(book.publisher);
                existingBooks.remove(book);
                if (existingBooks.isEmpty()) {
                    booksByPublisher.remove(book.publisher);
                }
            }
        }
        
        // 根据书名模糊查询书籍
        public void searchBooksByTitle(String keyword) {
            for (String title : booksByTitle.keySet()) {
                if (title.contains(keyword)) {
                    ArrayList<Book> books = booksByTitle.get(title);
                    System.out.println("书名匹配：" + title);
                    for (Book book : books) {
                        System.out.println("作者：" + book.authors + "，出版社：" + book.publisher + "，馆藏数量：" + book.quantity);
                    }
                }
            }
        }
        
        // 根据作者查询书籍
        public void searchBooksByAuthor(String author) {
            if (booksByAuthor.containsKey(author)) {
                ArrayList<Book> books = booksByAuthor.get(author);
                System.out.println("作者匹配：" + author);
                for (Book book : books) {
                    System.out.println("书名：" + book.title + "，出版社：" + book.publisher + "，馆藏数量：" + book.quantity);
                }
            }
        }
        
        // 根据出版社查询书籍
        public void searchBooksByPublisher(String publisher) {
            if (booksByPublisher.containsKey(publisher)) {
                ArrayList<Book> books = booksByPublisher.get(publisher);
                System.out.println("出版社匹配：" + publisher);
                for (Book book : books) {
                    System.out.println("书名：" + book.title + "，作者：" + book.authors + "，馆藏数量：" + book.quantity);
                }
            }
        }
        
        // 借阅书籍
        public void borrowBook(String studentId, Book book) {
            // 检查同学是否已借阅了三本书籍
            if (borrowedBooksCount.containsKey(studentId)) {
                int borrowedCount = borrowedBooksCount.get(studentId);
                if (borrowedCount >= 3) {
                    System.out.println("借阅失败，每位同学最多借阅三本书籍。");
                    return;
                }
            }
            
            // 检查书籍库存
            if (book.quantity <= 0) {
                System.out.println("借阅失败，库存不足。");
                return;
            }
            
            // 更新借阅数据
            if (borrowedBooksCount.containsKey(studentId)) {
                int borrowedCount = borrowedBooksCount.get(studentId);
                borrowedBooksCount.put(studentId, borrowedCount + 1);
            } else {
                borrowedBooksCount.put(studentId, 1);
            }
            
            // 更新书籍库存
            book.quantity--;
        }
        
        // 归还书籍
        public void returnBook(String studentId, Book book) {
            // 检查借阅数据是否存在
            if (!borrowedBooksCount.containsKey(studentId)) {
                System.out.println("归还失败，未找到借阅记录。");
                return;
            }
            
            // 更新借阅数据
            int borrowedCount = borrowedBooksCount.get(studentId);
            if (borrowedCount == 1) {
                borrowedBooksCount.remove(studentId);
            } else {
                borrowedBooksCount.put(studentId, borrowedCount - 1);
            }
            
            // 更新书籍库存
            book.quantity++;
        }
        
        // 根据学号查询借阅情况
        public void searchBorrowedBooksByStudentId(String studentId) {
            if (borrowedBooksCount.containsKey(studentId)) {
                System.out.println("学号匹配：" + studentId);
                int borrowedCount = borrowedBooksCount.get(studentId);
                System.out.println("借阅数量：" + borrowedCount);
            }
        }
    }
    
    public static void main(String[] args) {
        Library library = new Library();
        
        // 添加初始数据
        Book book1 = new Book("Java Programming", new ArrayList<>() {{
            add("John Smith");
        }}, "ABC Publications", 5);
        library.addBook(book1);
        
        Book book2 = new Book("Python Basics", new ArrayList<>() {{
            add("Alice Johnson");
        }}, "XYZ Books", 3);
        library.addBook(book2);
        
        Book book3 = new Book("Java Programming", new ArrayList<>() {{
            add("David Miller");
            add("Emily Davis");
        }}, "DEF Publishing", 2);
        library.addBook(book3);
        
        // 模糊查询书籍
        library.searchBooksByTitle("Java");
        
        // 查询作者对应的书籍
        library.searchBooksByAuthor("John Smith");
        
        // 查询出版社对应的书籍
        library.searchBooksByPublisher("XYZ Books");
        
        // 借阅书籍
        library.borrowBook("001", book1);
        library.borrowBook("001", book2);
        library.borrowBook("002", book3);
        
        // 归还书籍
        library.returnBook("001", book1);
        
        // 查询学号对应的借阅情况
        library.searchBorrowedBooksByStudentId("001");
    }
}
