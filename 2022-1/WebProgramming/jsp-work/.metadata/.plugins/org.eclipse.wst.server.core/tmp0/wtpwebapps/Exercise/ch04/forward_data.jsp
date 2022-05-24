<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<% 
	int data=Integer.parseInt(request.getParameter("num")); 

	
    for(int i=1;i<=9;i++)
    {
        out.println(data+" * "+i+" = "+data*i+"<br>");
    }
	%>
</body>
</html>