<?php 
	//$loaiphong=$_REQUEST['ID'];
	//echo 'Mã Loại Phòng Nhận Được: '.$loaiphong;
//khai bao ket noi
	$link= mysqli_connect("localhost", "root", "") or die("khong the ket noi den CSDL MySQL");
	mysqli_set_charset($link,"UTF8");
	mysqli_select_db($link,"DULIEU");
	$sql = "select * from THONGTINPHONG";
	$result= mysqli_query($link,$sql);
	//$rs = mysqli_query($link,"select * from thongtinphong where maloaiphong='$loaiphong'" );

	echo '<table border="1" width="100%">';
	echo '<caption>Dữ Liệu  Phòng </Caption>';
//tieu de cua bang chua du lieu  khi hienthi trang web

	echo "<TR><TH>Mã Phòng</TH><TH>Loại Phòng</TH><TH>Số Người Tối Đa</TH><TH>Tình Trạng</TH><TH>Tên Người Đặt</TH> <TH>Ngày Nhận</TH> <TH>Ngày Trả</TH>
	</TR>";

//cach 2: su dung hieu qua hon 

while ($row=mysqli_fetch_array($result,MYSQLI_BOTH)) {
		echo '<tr>
		<td align ="center">'.$row['maphong'].'</td>
		<td align ="center">'.$row['loaiphong'].'</td>
		<td align ="center">'.$row['songuoitoida'].'</td>
		<td align ="center">'.$row['tinhtrang'].'</td>
		<td align ="center">'.$row['tennguoidat'].'</td>
		<td align ="center">'.$row['ngaydatphong'].'</td>
		<td align ="center">'.$row['ngaytraphong'].'</td>
		
		</tr>';
		
}

	echo '</TABLE>';
	mysqli_free_result($result);
	mysqli_close($link);

 ?>
