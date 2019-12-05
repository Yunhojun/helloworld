using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class ObjScript : MonoBehaviour
{
    protected int HP = 100;//최대 체력
    protected float HpRegen = 0;//1초당 체력재생
    protected float AtkSpeed = 1;//초당 공격횟수
    protected float AtkDamage = 10;//공격력
    protected int AtkRange = 1;//사거리
    protected int CriticalRate = 5;//치명타확률
    protected int CriticalMultiplication = 200;//치명타 배율
    protected int Mana = 0;//기본마나
    protected float ManaRegen = 5;//초당 마나재생
    protected int Defense = 0;//방어력
    protected int SpellMultiplication = 100;//주문 배율
    protected float MoveSpeed = 1f;
    [SerializeField]
    protected Vector2 pos;
    protected GameObject Manager = null;
    protected bool isMove = true;
    float time = 0;
    float TimeForAtk = 0;
    public int ObjNum;

    // Start is called before the first frame update
    private void Awake()
    {
        Manager = GameObject.FindGameObjectWithTag("GameController");
    }

    void Start()
    {

    }

    // Update is called once per frame

    protected void FixedUpdate()
    {
        Vector2 target = findEnemy();
        if (isMove)
        {
            move(target);
        }
        time += Time.fixedDeltaTime;
        TimeForAtk += Time.fixedDeltaTime;
        if (TimeForAtk * AtkSpeed >= 1f)
        {
            Attack(target);
        }
        if (time >= 1f)
        {
            GainMana();
            GainHp();
            time = 0;
        }
        if(Mana >= 100)
        {
            
        }
    }

    void Update()
    {

    }

    protected Vector2 findEnemy()//가장 가까이 있는 적을 찾아 그 좌표를 리턴(target)
    {
        float dis = 100f;
        Vector2 targetPos = pos;
        bool isAtk = isAtkFunc(targetPos);
        Vector2[] enemy = GetEnemy();
        for(int i=0; i<10; i++)
        {
            float newdis = Vector2.Distance(enemy[i], pos);
            if(newdis < dis)
            {
                dis = newdis;
                targetPos = enemy[i];
            }
        }
        return targetPos;
    }

    protected void move(Vector2 target)//target에 가장 가까운 칸으로 이동
    {
        Vector2 temp = Vector2.zero;
        float tempdis = 100f;
        for (int x = -AtkRange; x<= AtkRange; x++)
        {
            for(int y=-AtkRange; y<=AtkRange; y++)
            {
                BoardScript targetBoard = Manager.GetComponent<CreateBoard>().getBoards(target.x - x, target.y -y).GetComponent<BoardScript>();
                if(!targetBoard.getisOnEnemy())
                {
                    Vector2 newpos = targetBoard.getpos();
                    float newdis = Vector2.Distance(newpos, pos);
                    if (newdis < tempdis)
                    {
                        tempdis = newdis;
                        temp = newpos;
                    }
                }
            }
        }
        print(temp.ToString());
        Vector3 dir = new Vector3(temp.x, transform.position.y, temp.y) - transform.position;
        transform.Translate(dir.normalized * MoveSpeed * Time.fixedDeltaTime, Space.Self);
    }

    protected void Damaged(float damage)
    {
        HP -= (int)(damage - Defense);
    }

    protected abstract void Spell();

    protected void Attack(Vector2 target)
    {
        GameObject targetObject = Manager.GetComponent<CreateBoard>().getBoards(target.x, target.y);
        if (isOnCenter()&& Vector2.Distance(pos,target) <= (float)AtkRange && GetEnemy(targetObject))
        {
            isMove = false;
            int damage = Mathf.RoundToInt(AtkDamage);
            int rand = Random.Range(0, 100);
            if(rand < CriticalRate)
            {
                damage = Mathf.RoundToInt(AtkDamage * CriticalMultiplication/100);
            }
            if (targetObject.GetComponent<BoardScript>().getUnit().tag == GetEnemyStr())
            {
                targetObject.GetComponent<BoardScript>().getUnit().GetComponent<ObjScript>().Damaged(damage);
            }
            TimeForAtk = 0f;
        }
        else
        {
            isMove = true;
        }
    }

    protected  bool isOnCenter()
    {
        Vector2 realPos = new Vector2(transform.position.x, transform.position.z);
        if(Vector2.Distance(realPos, pos) <= 0.2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    protected bool isAtkFunc(Vector2 target)//사거리 안에 적이 있는지 판단
    {
        int dis = Mathf.RoundToInt(Vector2.Distance(target, pos));
        if (dis <= AtkRange)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    protected void GainMana()
    {
        Mana += Mathf.RoundToInt(ManaRegen);
    }

    protected void GainHp()
    {
        HP += Mathf.RoundToInt(HpRegen);
    }

    protected void OnTriggerEnter(Collider other)
    {
        if(other.tag == "Plane")
        {
            pos = other.GetComponent<BoardScript>().getpos();
        }
    }

    protected virtual Vector2[] GetEnemy()
    {
        return Manager.GetComponent<CreateBoard>().getEnemy();
    }

    protected virtual string GetEnemyStr()
    {
        return "Enemy";
    }

    protected virtual bool GetEnemy(GameObject enemy)
    {
        return enemy.GetComponent<BoardScript>().getisOnEnemy();
    }
}
