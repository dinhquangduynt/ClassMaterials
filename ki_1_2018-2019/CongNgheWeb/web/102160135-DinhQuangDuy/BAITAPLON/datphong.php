<?php 
	$ID=$_REQUEST['ID'];
	$link= mysqli_connect("localhost", "root", "") or die("khong the ket noi den CSDL MySQL");
	mysqli_set_charset($link,"UTF8");
	mysqli_select_db($link,"DULIEU");
	$rs=mysqli_query($link, "select * from thongtinphong where maphong='$ID'");
	$row=mysqli_fetch_array($rs);
	mysqli_free_result($rs);
    mysqli_close($link);
 ?>

<html>
	<head>
		<title></title>
	</head>
	<body>
		<center>
			<form name="f1" action="xulydatphong.php?ID=<?php echo $row['maphong'];?>" method="POST">
			<table width="600px" border="0">
				<?php  echo '<tr>
						<td> Phòng</td>
						<td>'.$row['maphong'].'</td>
						</tr>';?>
				<?php  echo '<tr>
						<td>Loại Phòng</td>
						<td>'.$row['loaiphong'].'</td>
						</tr>';?>

				<?php  echo '<tr>
						<td>Số người tối đa</td>
						<td>'.$row['songuoitoida'].'</td>
						</tr>';?>
				<tr>
					<td>Tên người đặt</td>
					<td><input type="text" name="txtten"></td>
				</tr>
				<tr>
					<td>Số chứng minh</td>
					<td><input type="text" name="sochungminh" ></td>
				</tr>
				<tr>
					<td>Ngày Nhận</td>
					<td><input type="date" name="ngaynhan" ></td>
				</tr>
				<tr>
					<td>Ngày trả</td>
					<td><input type="date" name="ngaytra"></td>
				</tr>
				
			</table>
				
					<input type="Submit" name="b1" value="Đặt Phòng">
					<input type="Reset" name="b2" value="Reset">
				
		</form>
		</center>
	</body>
</html>

	
	

