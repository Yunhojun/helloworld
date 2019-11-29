using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class skillQScript : MonoBehaviour
{
    int damage;
    float Times = 1;
    GameObject Player;
    // Start is called before the first frame update
    void Start()
    {
        Player = GameObject.FindGameObjectWithTag("Player");
        damage = Mathf.RoundToInt(Player.GetComponent<CubeBehaviour>().damage * Times);
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.tag == "enemy")
        {
            other.GetComponent<enemyBehaviour>().HP -= damage;
            Destroy(gameObject);
        }       
    }

    private void OnBecameInvisible()
    {
        Destroy(gameObject);
    }
}
