<?php 
//khai bao ket noi
$link= mysqli_connect("localhost", "root", "") or die("khong the ket noi den CSDL MySQL");
	mysqli_set_charset($link,"UTF8");
	mysqli_select_db($link,"DULIEU");
	$sql = "select *from PHONGBAN";
	$result= mysqli_query($link,$sql);

echo '<table border="1" width="100%">';
echo '<caption>Du Lieu bang Phong Bang</Caption>';
//tieu de cua bang chua du lieu  khi hienthi trang web

echo "<TR><TH>Ma So</TH><TH>Mo Ta</TH><TH>Thoi Gian</TH><TH>Xoa PB</TH> </TR>";

//cach 2: su dung hieu qua hon 

while ($row=mysqli_fetch_array($result,MYSQLI_BOTH)) {
	# code...
	
	echo '<tr>
	<td>'.$row['IDPB'].'</td>
	<td>'.$row['mota'].'</td>
	<td>'.$row['thoigian'].'</td>
	<td align ="center">
	<a href="xulyxoa.php?IDPB='.$row['IDPB'].'"><input type="submit" size="20" name="xoa" value="Xoa phong ban"></a>

	</td></tr>';
}
	
	echo '</TABLE>';
	echo'<center>';
	echo '<td align ="center">
	<a href="xulyxoa.php"><input type="submit" size="20" name="xoa" value="Xoa tat ca"></a>
	</td></tr>';
	echo'</center>';
mysqli_free_result($result);
mysqli_close($link);

 ?>