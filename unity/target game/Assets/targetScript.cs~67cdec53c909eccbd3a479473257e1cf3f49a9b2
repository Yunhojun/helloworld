using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class targetScript : MonoBehaviour
{
    [SerializeField]
    private float LifeCycle = 5f;
    [SerializeField]
    private targetinstance Creater;
    // Start is called before the first frame update
    void Start()
    {
        Creater = GameObject.Find("GameObject").GetComponent<targetinstance>(); 
    }
     
    // Update is called once per frame
    void Update()
    {
        LifeCycle -= Time.deltaTime;
        if(LifeCycle <= 0)
        {
            Destroy(this.gameObject);
        }
    }

    public void OnDestroy()
    {
        Creater.arr[((int)transform.position.x / 3 + 3) + (((int)transform.position.y / 3 + 2) * 7)] = false;
    }
}
