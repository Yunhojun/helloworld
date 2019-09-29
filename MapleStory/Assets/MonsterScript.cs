    using System.Collections;
    using System.Collections.Generic;
    using UnityEngine;

    public class MonsterScript : MonoBehaviour
    {
        private float Velocity;
        [SerializeField]
        private Animator animator;
        private bool run = false;
        [SerializeField]
        public float Hp = 1;
        private float attackdelay = 0;
        

        // Start is called before the first frame update
        void Start()
        {
            animator = GetComponent<Animator>();
            Velocity = Random.Range(1, 3) * 2;
        }

        // Update is called once per frame
        void Update()
        {
            attackdelay += Time.deltaTime;  
            move();
            if (Hp <= 0)
            {
                MonsterDead();
            }
            
            attack();
        }

        public void move()
        {
            transform.Translate(new Vector3(-1f, 0, 0) *Velocity * Time.deltaTime);

            if (Velocity >= 3.0f)
            {
                run = true;
            }
            else
            {
                run = false;
            }
            animator.SetBool("Run", run);
        }

        public void MonsterDead()
        {
            Velocity = 0;
            Destroy(gameObject,1f);
            animator.SetFloat("Hp", Hp);

        }

    public void OnBecameInvisible()
        {
            Destroy(gameObject);
        }


        public void attack()
        {
            if (Input.GetKeyDown("space"))
            {
                if (transform.position.x <= -11 || transform.position.x>=-12)
                {
                    print("attack");
                    GetComponent<MonsterScript>().Hp = 0;
                }
                   
               
            }
        }
    }
