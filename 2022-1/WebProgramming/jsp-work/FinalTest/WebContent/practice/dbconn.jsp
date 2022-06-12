<%@ page import="java.sql.*"%>
<%
Connection conn=null;
String url="jdbc:mysql://localhost:3306/Test_board";
String user="root";
String password="root";
Class.forName("com.mysql.jdbc.Driver");
conn=DriverManager.getConnection(url, user, password);
%>