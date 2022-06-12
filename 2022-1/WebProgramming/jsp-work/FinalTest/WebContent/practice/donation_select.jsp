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
	<table border="1">
		<tr>
			<th>아이디</th>
			<th>이름</th>
			<th>기부금</th>
		</tr>
		<%
			ResultSet rs=null;
		PreparedStatement pstmt=null;
		try{
			String sql="select *from Test_board";
			pstmt=conn.prepareStatement(sql);
			rs=pstmt.executeQuery();
			while(rs.next()){
				String id=rs.getString("id");
				String name=rs.getString("name");
				String dona=rs.getString("donation");
		%>
		<tr>
			<td><%=id %></td>
			<td><%=name %></td>
			<td><%=name %></td>
		</tr>
		<%
			}
		}catch(SQLException ex){
			out.println("Test_board 테이블 호출이 실패했습니다. <br>");
			out.println("SQLExecption: "+ ex.getMessage());
		}finally{
			if(rs!=null) rs.close();
			if(pstmt!=null) pstmt.close();
		}
		%>
	</table>
</body>
</html>