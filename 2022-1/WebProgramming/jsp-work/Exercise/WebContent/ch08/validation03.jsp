<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Validation</title>
</head>
<script type="text/javascript">
	function checkPasswd(){
		let id=document.getElementById("id").value;
		let passwd=document.getElementById("passwd").value;
		if(id.length==0){
			alert("아이디를 입력해주세요");
			document.getElementById("id").focus();
			return;
		}
		if(passwd.length==0){
			alert("비밀번호를 입력해주세요");
			return;
		}else{
			if(passwd!=passwdConfirm){
				alert("비밀번호가 일치하지 않습니다.");
				return false;
			}
		}
		if(!pattern1.text(passwd)||!pattern2.text(passwd)||!pattern3.text(passwd)||passwd.length<8||passwd.length>50){
			alert("영문+숫자+특수히고 8자리 이상으로 구성하여야 합니다.");
		}
	}
</script>
<body>
	<form name="form" action="validation_process.jsp" method="post">
		<p> 아 이 디 : <input type="text" name="id">
		<p> 비밀번호 : <input type="password" name="passwd">
		<p> <input type="submit" value="전송" onClick="checkPasswd()">
	</form>
</body>
</html>