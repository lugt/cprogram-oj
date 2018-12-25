CURDIRD=$(pwd)
ORIG_NAME=$1
fullfile=$1
fullname="${fullfile##*/}"
dir="${fullfile%/*}"
extension="${fullname##*.}"
filename="${fullname%.*}"
APP_NAME=${filename}
SRC_DIR="$(pwd)"
TARG_DIR="$(pwd)"
RUN_CMD="cat $TARG_DIR/$APP_NAME.in | java $APP_NAME > $TARG_DIR/$APP_NAME.log"


if [ -z $APP_NAME ]; then
    echo "Usage : $0 CLASS_NAME"
    exit 3
fi


echo "-------------------------------------"
echo " Running in $CURDIRD"
echo " Input : "
echo "-------------------------------------"
if [ ! -f $SRC_DIR/$APP_NAME".in" ]; then
    echo "Cannot locate $APP_NAME.in, abort"
    exit 3
fi
cp $SRC_DIR/$APP_NAME".in" $TARG_DIR
cp $SRC_DIR/$APP_NAME".out" $TARG_DIR
cd $TARG_DIR
cat $APP_NAME.in
echo
echo " "
echo " "
echo "-------------------------------------"
echo " Output: "
echo "-------------------------------------"
if [ ! -f $TARG_DIR/$APP_NAME.out ]; then
    echo "Cannot locate $TARG_DIR/$APP_NAME.out, abort"
    exit 3
fi
cat $TARG_DIR/$APP_NAME.out
echo " "
echo " "
echo "-------------------------------------"
echo " Running make "
echo "-------------------------------------"
javac -g $SRC_DIR/$APP_NAME.java

echo " "
echo " "
echo "-------------------------------------"
echo " Running $RUN_CMD "
echo "-------------------------------------"
cat $TARG_DIR/$APP_NAME.in | $TARG_DIR/$APP_NAME > $TARG_DIR/$APP_NAME.log
echo " "
echo " "

echo " "
echo " "
echo "-------------------------------------"
echo " Result "
echo "-------------------------------------"
cat $TARG_DIR/$APP_NAME.log
diff $TARG_DIR/$APP_NAME.log $TARG_DIR/$APP_NAME.out
if [ $? -eq 0 ]; then
    echo "***************"
    echo "Test Success !"
    echo "***************"
else
    echo "***************"
    echo "Test Failed  !"
    echo "***************"
fi
