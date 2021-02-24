<!DOCTYPE html>
<html lang="zh-cn">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <?php
        require('config.php');
        session_start();
		
        if(isset($_SESSION['login'])&&($_SESSION['login']==1)){
        }else{
            echo "<script>alert( '(ヾ(o◕∀◕)ﾉ要先登录凹！' ); window.location.href = 'login.php'; </script>";
            exit;
        }
        ?>

    </head>
    <body>
    后台登录成功！
    <a href="logout.php">退出登录</a>

    </body>


</html>