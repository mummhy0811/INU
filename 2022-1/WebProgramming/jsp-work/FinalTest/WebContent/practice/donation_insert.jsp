<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%@include file="dbconn.jsp" %>
<%
request.setCharacterEncoding("utf-8");
String id=request.getParameter("userid");
String name=request.getParameter("userpw");
String dona=request.getParameter("donation");
PreparedStatement pstmt=null;
try{
	String sql="insert into test_board(id, name, donation) values(?,?,?)";
	pstmt=conn.prepareStatement(sql);
	pstmt.setString(1, id);
	pstmt.setString(2, name);
	pstmt.setInt(3, Integer.parseInt(dona));
	pstmt.executeUpdate();
	response.sendRedirect("donation_select.jsp");
}catch(SQLException ex){
	out.println("테이블 삽입이 실패했습니다.<br>");
	out.println("SQLException: "+ex.getMessage());
}finally{
	if(pstmt!=null) pstmt.close();
	if(conn!=null)conn.close();
}
%>
</body>
</html>