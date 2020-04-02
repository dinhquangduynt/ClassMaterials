<?php 
//khai bao ket noi
$link= mysqli_connect("localhost", "root", "") or die("khong the ket noi den CSDL MySQL");
	mysqli_set_charset($link,"UTF8");
	mysqli_select_db($link,"DULIEU");
	$sql = "select *from THONGTINPHONG";
	$result= mysqli_query($link,$sql);

echo '<table border="1" width="100%">';
echo '<caption>Dữ Liệu  Phòng</Caption>';
//tieu de cua bang chua du lieu  khi hienthi trang web

echo "<TR><TH>Mã Phòng</TH><TH>Loại Phòng</TH><TH>Số Người Tối Đa</TH><TH>Tình Trạng</TH><TH>Tên Người Đặt</TH> <TH>Ngày Nhận</TH> <TH>Ngày Trả</TH><TH>Cập Nhật</TH>
	</TR>";


while ($row=mysqli_fetch_array($result,MYSQLI_BOTH)) {
	# code...
	
		echo '<tr>
		<td align ="center">'.$row['maphong'].'</td>
		<td align ="center">'.$row['loaiphong'].'</td>
		<td align ="center">'.$row['songuoitoida'].'</td>
		<td align ="center">'.$row['tinhtrang'].'</td>
		<td align ="center">'.$row['tennguoidat'].'</td>
		<td align ="center">'.$row['ngaydatphong'].'</td>
		<td align ="center">'.$row['ngaytraphong'].'</td>
		<td align ="center">
		<a href="form_updatephong.php?ID='.$row['maphong'].'">
		<input type="submit" size="20" name="datphong" value="Cập Nhật"> </a>
		</td>
		</tr>';
}
echo '</TABLE>';
mysqli_free_result($result);
mysqli_close($link);

 ?>