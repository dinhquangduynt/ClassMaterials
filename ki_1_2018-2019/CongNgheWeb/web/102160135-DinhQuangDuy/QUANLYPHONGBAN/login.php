<!DOCTYPE html>
<html lang="en" >

<head>
  <meta charset="UTF-8">
  <title>Login Form</title>
  
  
  <link rel='stylesheet' href='http://ajax.googleapis.com/ajax/libs/jqueryui/1.11.2/themes/smoothness/jquery-ui.css'>

      <link rel="stylesheet" href="css/style.css">

  
</head>

<body>

  <link href='https://fonts.googleapis.com/css?family=Ubuntu:500' rel='stylesheet' type='text/css'>

<div class="login">
  <div class="login-header">
    <h1>Login</h1>
  </div>
  <div class="login-form">

	<form name="f1" method="POST" action="xulylogin.php">
		<table>
			<caption>Login</caption>
			<tr>
				<td>User</td>
				<td><input type="text" name="t1" placeholder="Username"></td>
			</tr>
			<tr>
				<td>Password</td>
				<td><input type="password" name="p1" placeholder="Password"></td>
			</tr>
			
		</table>

				<input type="submit" name="s1" value="Login" class="login-button">
				<input type="reset" name="r1" value="Reset"></form></div>
	</form>
  </div>
</div>
<div class="error-page">
  <div class="try-again">Error: Try again?</div>
</div>
  <script src='http://cdnjs.cloudflare.com/ajax/libs/jquery/2.1.3/jquery.min.js'></script>
<script src='http://ajax.googleapis.com/ajax/libs/jqueryui/1.11.2/jquery-ui.min.js'></script>

  

    <script  src="js/index.js"></script>




</body>

</html>
