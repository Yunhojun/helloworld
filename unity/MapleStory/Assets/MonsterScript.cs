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
        public GameObject player;

        // Start is called before the first frame update
        void Start()
        {
            animator = GetComponent<Animator>();
            Velocity = Random.Range(1, 3) * 2;
        
            AniamtedDead();
            AnimatedMove();
            
            
        }

        // Update is called once per frame
        void Update()
        { 
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
            AnimatedMove();
        }

        public void AnimatedMove()
        {

            animator.SetBool("Run", run);
        }

        public void MonsterDead()
        {
            Velocity = 0;
            Destroy(gameObject,1f);
            
            AniamtedDead();
        }

        public void AniamtedDead()
    {

        animator.SetFloat("Hp", Hp);
    }

    public void OnBecameInvisible()
        {
            Destroy(gameObject);
        }


        public void attack()
            {
        {
            if (Input.GetKeyDown("space"))
                if (transform.position.x - player.transform.position.x <= 2 )
                {
                    print("attack");
                    GetComponent<MonsterScript>().Hp = 0;
                }               
            }
        }
    }
