<?php  
    require('config.php');
    global $config;
    $user=$config['user'];
    $pswd=$config['pswd'];

    function test_input($data){
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }
    $userin = $pswdin = null;
  ?>
<!DOCTYPE html>
<html lang="zh-cn">
    <head>
    <meta charset="utf-8">
        <title>Login - </title>
        <meta name="theme-color" content="#40a9ff" />
        <meta name="msapplication-TileColor" content="#40a9ff" />
        <link type="text/css" rel="stylesheet" href="asset/css/admin.css" />
        <!--<script src="https://www.google.com/recaptcha/enterprise.js?onloadCallback" async defer></script>-->
    </head>
    <body class="admin">
        <div class="control" align="center">
            <h2 class="ctrl-heading">Login to </h2>
            <form method="post" class="login-form" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
                <br>
                <input name="userid" type="text" placeholder="User Account">
                <br>
                <input name="passwd" type="password" placeholder="Password">
                <br>
                <!--
                <label class="checkbox" style="color: #b6b6b6;" >
                    <input type="checkbox" value="remember-me" /> Remember Me
                </label>
                <br>
                    <div class="g-recaptcha" data-callback="robot" data-sitekey="keykeykeykeykey" data-action="Admin login page" ></div>
					-->
                <input type="submit" name="submit" value="Submit">
                <br>
                <?php
                session_start();
                $userin=$_POST['userid'];
                $pswdin=$_POST['passwd'];
                if(isset($_POST['submit'])){
                    if($userin==''||$pswdin==''){
                        echo "<center> kora 用户名还是密码没写啊喂 </center>";
                        exit;
                    }
                    if($userin == $user && $pswdin == $pswd){
                        $_SESSION['login'] = 1;
                        echo "<script>window.location.href = 'admin.php'</script>";
                    }
                    else{
                        $_SESSION['login'] = 0;
                        echo "<center>不会吧不会吧，这就忘记账户了 o(*≧▽≦)ツ┏━┓</center>";
                        }
                }
                ?>
                <br>
            </form>
        </div>
    </body>
</html>