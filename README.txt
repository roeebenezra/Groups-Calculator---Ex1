
מחשבון קבוצות
מגישים: יעקב חיימוף 318528510
	   רועי בן עזרא 20123994

תרגיל זה עוסק ביצירת מחשבון קבוצות המאפשר פעולות על קבוצות הקלט, כמו כן, יצירת פעולות חדשות מהפעולות הבסיסיות בתפריט האפשרויות המוצג בתחילת ריצת התוכנית.
פעולות בסיסיות על הקבוצות: איחוד,חיתוך,הפרש.
פעולות מוכרבות שניתן לייצר: הרכבה בין פעולות, הכפלה בין איברי הקבוצות.
פעולות נוספות בתפריט: מחיקת פעולה ((del OperationNum,
	עזרה (help), יציאה (exit).

תיכון: אובייקט ראשי calculator המחזיק וקטור של מצביעים חכמים לאובייקטים מסוג operation. 
בכל אובייקט פעולה מתבצעים החישובים וההדפסות הנצרכות לטובת                   הצגת התפריט\הצגת תוצאת הפעולה. כל אובייקט פעולה מחזיק מצביעים חכמים left & right עבור הפעולות שיתווספו תחתיו בעץ. 
מחלקת operation היא מחלקה אבסטרקטית וכל פעולה יורשת ממנה.
קבצים: 
Calculator: מחלקה ראשית שמנהלת לולאה מרכזית של התוכנית ומחזיקה וקטור מצביעים חכמים של כל הפעולות.

Operation: מחלקה אבסטרקטית שכל פעולה יורשת ממנה. מממשת פונקציות הנחוצות עבור כל הפעולות כדי שבמחלקות הפעולה המימושים יהיו ספציפיים עבור אותה הפעולה.
Union: מחלקת פעולת איחוד.
Diffrence: מחלקת פעולת הפרש.
Intersection: מחלקת פעולת חיתוך.
Product: מחלקת פעולת הכפלה.
Composite: מחלקת פעולת הרכבה של פעולות.

:Set מחלקה עבור אובייקט יחיד של קבוצה.
Print: מחלקה עבור הדפסת תוצאת החישוב (eval) והדפסת תפריטים.
Macros: includes & using שנחוצים עבור כל המחלקות.

מבנה נתונים עיקרי: וקטור מצביעים חכמים operation 

אלגורתמים ראויים לציון: 
באגים: לא ידוע
