$count = $args.count
$baseDir = ""
function CreateFile($path) {
    Write-Output $path
    if (-not(Test-Path $path)) {
        new-item  $path -ItemType Directory
    }
}



if ($count -eq 0) {
    CreateFile("bin");
}
else {
    $baseDirFlag = "--basedir"
    if ($args.Contains($baseDirFlag)) {
        $baseDirIndex = $args.IndexOf($baseDirFlag)
        if ($baseDirIndex -eq $count) {
            throw "Please add a base dir after the '$($baseDirFlag)' flag"
        }
        else {
            $baseDir = $args[$baseDirIndex+1] 
        }
    }
    foreach ($arg in $args) {
        if (($arg -ne $baseDirFlag) -and ($arg -ne $baseDir)) {
            switch ($arg) {
                "bin" { CreateFile($baseDir+"bin"); Break }
                "debug" { CreateFile($baseDir+"bin"); CreateFile($baseDir+"bin\debug"); Break }
                "test" { CreateFile($baseDir+"bin"); CreateFile($baseDir+"bin\test"); Break }
                "release" { CreateFile($baseDir+"bin"); CreateFile($baseDir+"bin\release"); Break }
                Default { throw "The fuck? $($arg) is not in the normal list of items" }
            }
        }
    }
}

