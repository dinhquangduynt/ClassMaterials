<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>

	<center>
		<form name="f1" action="xulyinsert.php" method="POST">
			<table width="600px" border="0">
				<tr>
					<td>Mã Phòng</td>
					<td><input type="Text" size="20" name="txtMaphong"></td>
				</tr>
				<tr>
					<td>Loại Phòng</td>
					<td><input type="Text" size="20" name="txtLoaiphong"></td>
				</tr>
				<tr>
					<td>Số Người Tối Đa</td>
					<td><input type="Text" size="20" name="txtsonguoi"></td>
				</tr>
				<tr>
					<td>Tên Người Đặt</td>
					<td><input type="Text" size="20" name="txtten"></td>
				</tr>
				<tr>
					<td>Ngày Nhận</td>
					<td><input type="date" name="ngaynhan"></td>
				</tr>
				<tr>
					<td>Ngày Trả</td>
					<td><input type="date" name="ngaytra"></td>
				</tr>
			</table>
			<input type="Submit" name="b1" value="Thêm">
			<input type="Reset" name="b2" value="Reset">
		</form>
	</center>

</body>
</html>