<?php 
	$maphong=$_REQUEST['ID'];
	$link= mysqli_connect("localhost", "root", "") or die("khong the ket noi den CSDL MySQL");
	mysqli_set_charset($link,"UTF8");
	mysqli_select_db($link,"DULIEU");
	$rs=mysqli_query($link, "select * from thongtinphong where maphong='$maphong'");
	$row=mysqli_fetch_array($rs);
	mysqli_free_result($rs);
    mysqli_close($link);
 ?>

<html>
	<head>
		<title>Cap nhat phong ban</title>
	</head>
	<body>
		<center>
			<form name="f1" action="xulyupdatephong.php?ID=<?php echo $row['maphong'];?>" method="POST">
			<table width="600px" border="0">
				<?php  echo '<tr>
						<td> Phòng</td>
						<td>'.$maphong.'</td>
						</tr>';?>
				<?php  echo '<tr>
						<td>Loại Phòng</td>
						<td>'.$row['loaiphong'].'</td>
						</tr>';?>
				<tr>
					<td>Số người tối đa</td>
					<td><input type="text" name="txtsonguoi" value="<?php echo $row['songuoitoida']; ?>">
					</td>
				</tr>
				<tr>
					<td>Tình trạng</td>
					<td><input type="text" name="txttt"  value=" <?php echo $row['tinhtrang']; ?>"></td>
				</tr>
				<tr>
					<td>Tên người đặt</td>
					<td><input type="text" name="txtten" value="<?php echo $row['tennguoidat']; ?>"></td>
				</tr>
				<tr>
					<td>Ngày Nhận</td>
					<td><input type="date" name="ngaynhan" value="<?php echo $row['ngaydatphong']; ?>"></td>
				</tr>
				<tr>
					<td>Ngày trả</td>
					<td><input type="date" name="ngaytra" value="<?php echo $row['ngaytraphong']; ?>"></td>
				</tr>
				
			</table>
				
					<input type="Submit" name="b1" value="Cập Nhật">
					<input type="Reset" name="b2" value="Reset">
				
		</form>
		</center>
	</body>
</html>

	
	

